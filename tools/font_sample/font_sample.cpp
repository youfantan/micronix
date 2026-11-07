#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <format>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ft2build.h>
#include "luciferin/font.h"
#include FT_FREETYPE_H
#include FT_BITMAP_H

using namespace micronix::luciferin;

#define ASSERT(cond, msg) if (cond) { std::cout << "Fatal at expression '" << #cond << "': " << msg << std::endl; exit(EXIT_FAILURE); }

struct quantization_config {
    std::string font_path;
    std::string font_name;
    std::string quantization;
    std::string quantization_args;
    std::string render_mode;
    uint32_t font_height;
    std::vector<char32_t> characters;
};

std::vector<char32_t> utf8toutf32(const std::string& input) {
    std::vector<char32_t> output;
    output.reserve(input.size());
    size_t i = 0;
    while (i < input.size()) {
        auto first = static_cast<uint8_t>(input[i]);
        char32_t cp;
        size_t extra_bytes;
        if (first <= 0x7F) {
            cp = first;
            extra_bytes = 0;
        } else if ((first & 0xE0) == 0xC0) {
            cp = first & 0x1F;
            extra_bytes = 1;
        } else if ((first & 0xF0) == 0xE0) {
            cp = first & 0x0F;
            extra_bytes = 2;
        } else if ((first & 0xF8) == 0xF0) {
            cp = first & 0x07;
            extra_bytes = 3;
        } else {
            std::cout << "Invalid UTF-8 leading byte" << std::endl;
            exit(EXIT_FAILURE);
        }
        ASSERT(i + extra_bytes >= input.size(), "Truncated UTF-8 sequence");
        for (size_t j = 1; j <= extra_bytes; ++j) {
            auto next = static_cast<uint8_t>(input[i + j]);
            ASSERT((next & 0xC0) != 0x80, "Invalid UTF-8 continuation byte");
            cp = (cp << 6) | (next & 0x3F);
        }
        constexpr char32_t minimumByLength[] = {
            0, 0, 0x80, 0x800, 0x10000
        };
        const size_t length = extra_bytes + 1;
        ASSERT(cp < minimumByLength[length], "Overlong UTF-8 sequence");
        ASSERT(cp >= 0xD800 && cp <= 0xDFFF, "UTF-8 contains surrogate code point");
        ASSERT(cp > 0x10FFFF, "Code point exceeds U+10FFFF");
        output.push_back(cp);
        i += length;
    }
    return output;
}

std::vector<quantization_config> load_configs(const std::string& config_path) {
    std::ifstream config_fin(config_path, std::ios::in | std::ios::binary);
    std::string strn;
    std::getline(config_fin, strn);
    uint32_t n = std::atoi(strn.c_str());
    std::vector<quantization_config> configs(n);
    for (uint32_t i = 0; i < n; ++i) {
        auto& config = configs[i];
        std::string settings;
        std::getline(config_fin, settings);
        std::stringstream settings_stream(settings);
        settings_stream >> config.font_path >> config.font_name >> config.quantization >> config.render_mode >> config.font_height;
        std::getline(config_fin, config.quantization_args);
        std::string u32characters;
        std::getline(config_fin, u32characters);
        config.characters = std::move(utf8toutf32(u32characters));
        std::erase_if(config.characters, [](const char32_t c) {
            return c == '\r';
        });
    }
    return configs;
}

template<typename T>
constexpr static T round_up(T n, T div) {
    return (n + div - 1) / div;
}

void validate_glyph_bitmap(char32_t unicode, FT_GlyphSlot glyph) {
    const auto& bmp = glyph->bitmap;
    ASSERT(bmp.width > 255, std::format("Character U+{} glyph width '{}' is illegal", static_cast<uint32_t>(unicode), bmp.width));
    ASSERT(bmp.rows > 255, std::format("Character U+{} glyph height '{}' is illegal", static_cast<uint32_t>(unicode), bmp.rows));
    ASSERT(bmp.pitch < static_cast<int>(bmp.width), std::format("Character U+{} glyph pitch '{}' is illegal", static_cast<uint32_t>(unicode), bmp.pitch));
    ASSERT(bmp.width != 0 && bmp.rows != 0 && bmp.buffer == nullptr, std::format("Character U+{} glyph bitmap is empty", static_cast<uint32_t>(unicode)));
    ASSERT(bmp.width != 0 && bmp.rows != 0 && bmp.pixel_mode != FT_PIXEL_MODE_GRAY, std::format("Character U+{} glyph is not 8-bit grayscale", static_cast<uint32_t>(unicode)));
}

void validate_glyph_metrics(char32_t unicode, FT_GlyphSlot glyph) {
    const auto advance = glyph->advance.x >> 6;
    ASSERT(advance < 0 || advance > 255, std::format("Advance '{}' of glyph U+{} is out of range", advance, static_cast<uint32_t>(unicode)));
    ASSERT(glyph->bitmap_left < -128 || glyph->bitmap_left > 127, std::format("BearingX '{}' of glyph U+{} is out of range", glyph->bitmap_left, static_cast<uint32_t>(unicode)));
    ASSERT(glyph->bitmap_top < -128 || glyph->bitmap_top > 127, std::format("BearingY '{}' of glyph U+{} is out of range", glyph->bitmap_top, static_cast<uint32_t>(unicode)));
}

std::vector<int> parse_thresholds(const std::string& args, size_t count) {
    std::vector<int> thresholds(count);
    std::stringstream ss(args);
    for (size_t i = 0; i < count; ++i) {
        ASSERT(!(ss >> thresholds[i]), std::format("Expected {} quantization thresholds", count));
        ASSERT(thresholds[i] <= 0 || thresholds[i] >= 255, "Illegal quantization argument");
        if (i != 0) {
            ASSERT(thresholds[i] <= thresholds[i - 1], "Quantization thresholds must be strictly increasing");
        }
    }
    std::string trailing;
    ASSERT(static_cast<bool>(ss >> trailing), std::format("Expected exactly {} quantization thresholds", count));
    return thresholds;
}

std::vector<uint8_t> make_glyph_meta(char32_t unicode, FT_GlyphSlot glyph, const std::vector<uint8_t>& bits) {
    validate_glyph_metrics(unicode, glyph);
    const auto& bmp = glyph->bitmap;
    glyph_meta glyph_meta {
        .unicode = static_cast<u32>(unicode),
        .width = static_cast<u8>(bmp.width),
        .height = static_cast<u8>(bmp.rows),
        .advance = static_cast<u8>(glyph->advance.x >> 6),
        .bearing_x = static_cast<i8>(glyph->bitmap_left),
        .bearing_y = static_cast<i8>(glyph->bitmap_top)
    };
    std::vector<uint8_t> data(sizeof(glyph_meta) + bits.size());
    std::memcpy(data.data(), &glyph_meta, sizeof(glyph_meta));
    if (!bits.empty()) std::memcpy(data.data() + sizeof(glyph_meta), bits.data(), bits.size());
    return data;
}

std::vector<uint8_t> Q1_2_4(char32_t unicode, FT_GlyphSlot glyph, const std::string& args, glyph_quantization quantization_type) {
    auto& bmp = glyph->bitmap;
    validate_glyph_bitmap(unicode, glyph);
    unsigned bits_per_pixel;
    switch (quantization_type) {
        case glyph_quantization::Q1H:
        case glyph_quantization::Q1V:
            bits_per_pixel = 1;
            break;
        case glyph_quantization::Q2H:
        case glyph_quantization::Q2V:
            bits_per_pixel = 2;
            break;
        case glyph_quantization::Q4H:
        case glyph_quantization::Q4V:
            bits_per_pixel = 4;
            break;
        default:
            ASSERT(true, std::format("Unsupported low-depth quantization: {}", static_cast<int>(quantization_type)));
    }
    const bool vertical = quantization_type == glyph_quantization::Q1V
        || quantization_type == glyph_quantization::Q2V
        || quantization_type == glyph_quantization::Q4V;
    const unsigned pixels_per_byte = 8u / bits_per_pixel;
    const unsigned threshold_count = (1u << bits_per_pixel) - 1;
    auto thresholds = parse_thresholds(args, threshold_count);
    auto width = vertical ? bmp.width : round_up(bmp.width, pixels_per_byte);
    auto height = vertical ? round_up(bmp.rows, pixels_per_byte) : bmp.rows;
    std::vector<uint8_t> bits(width * height);
    auto sample = [](uint8_t pixel, int* thresholds, int n) {
        uint8_t q = 0;
        for (int i = 0; i < n; ++i) {
            if (pixel < thresholds[i]) return q;
            ++q;
        }
        return q;
    };
    for (u32 y = 0; y < bmp.rows; ++y) {
        for (u32 x = 0; x < bmp.width; ++x) {
            uint8_t p = bmp.buffer[x + y * bmp.pitch];
            auto level = sample(p, thresholds.data(), static_cast<int>(thresholds.size()));
            u32 bx;
            u32 by;
            unsigned shift;
            if (vertical) {
                bx = x;
                by = y / pixels_per_byte;
                shift = (y % pixels_per_byte) * bits_per_pixel;
            } else {
                bx = x / pixels_per_byte;
                by = y;
                shift = (x % pixels_per_byte) * bits_per_pixel;
            }
            bits[bx + by * width] |= static_cast<uint8_t>(level << shift);
        }
    }
    return make_glyph_meta(unicode, glyph, bits);
}

std::vector<uint8_t> Q8(char32_t unicode, FT_GlyphSlot glyph, const std::string&) {
    auto& bmp = glyph->bitmap;
    validate_glyph_bitmap(unicode, glyph);
    auto width = bmp.width;
    auto height = bmp.rows;
    std::vector<uint8_t> bits(width * height);
    for (auto y = 0; y < bmp.rows; ++y) {
        for (auto x = 0; x < bmp.width; ++x) {
            uint8_t p = bmp.buffer[x + y * bmp.pitch];
            bits[x + y * width] = p;
        }
    }
    return make_glyph_meta(unicode, glyph, bits);
}

template<typename T>
class array_view {
    uint8_t** base_;
    uint32_t offset_;
    uint32_t size_;
public:
    array_view(uint8_t** base, uint32_t offset, uint32_t size) : base_(base), offset_(offset), size_(size) {

    }
    array_view(array_view&) = delete;
    array_view(array_view&&) = delete;

    T& operator[](uint32_t i) {
        return reinterpret_cast<T*>(*base_ + offset_)[i];
    }

    const T& operator[](uint32_t i) const {
        return reinterpret_cast<T*>(*base_ + offset_)[i];
    }

    ~array_view() = default;
};

class byte_buffer {
    uint8_t* data_;
    uint8_t** base_;
    uint32_t index_;
    uint32_t capacity_;

    constexpr static uint32_t InitialCapacity = 32 * 1024;
    constexpr static uint32_t MinExpandCapacity = 1024;
public:
    byte_buffer() : capacity_(InitialCapacity), index_(0), data_(new uint8_t[InitialCapacity]), base_(new uint8_t*(data_)) {
    }

    byte_buffer(byte_buffer& other) : data_(new uint8_t[other.capacity_]), base_(new uint8_t*(data_)), index_(0), capacity_(other.capacity_) {
        *base_ = data_;
        memcpy(data_, other.data_, capacity_);
    }

    byte_buffer(byte_buffer&& other) noexcept : data_(other.data_), base_(other.base_), index_(other.index_), capacity_(other.capacity_) {
        other.base_ = nullptr;
        other.data_ = nullptr;
    }

    template<typename T>
    void append(const std::vector<T>& buffer) {
        uint32_t require_capacity = index_ + buffer.size() * sizeof(T);
        if (require_capacity > capacity_) expand(require_capacity);
        if (!buffer.empty()) {
            std::memcpy(data_ + index_, buffer.data(), buffer.size() * sizeof(T));
            index_ += buffer.size() * sizeof(T);
        }
    }

    template<typename T>
    void append(const T& data) {
        uint32_t require_capacity = index_ + sizeof(T);
        if (require_capacity > capacity_) expand(require_capacity);
        memcpy(data_ + index_, &data, sizeof(T));
        index_ += sizeof(T);
    }

    void reserve(uint32_t size) {
        uint32_t require_capacity = index_ + size;
        if (require_capacity > capacity_) expand(require_capacity);
        index_ += size;
    }

    template<typename T>
    array_view<T> get_array_view(uint32_t offset, uint32_t size) {
        return { base_, offset, size };
    }

    uint8_t& operator[](uint32_t i) {
        return data_[i];
    }

    void expand(uint32_t new_capacity) {
        if (new_capacity - capacity_ <= MinExpandCapacity) {
            new_capacity = capacity_ + MinExpandCapacity;
        }
        auto* new_buffer = new uint8_t[new_capacity];
        memcpy(new_buffer, data_, capacity_);
        delete[] data_;
        capacity_ = new_capacity;
        data_ = new_buffer;
        *base_ = data_;
    }

    uint32_t index() {
        return index_;
    }

    uint32_t capacity() const {
        return capacity_;
    }

    ~byte_buffer() {
        if (data_ != nullptr) {
            delete base_;
            delete[] data_;
        }
    }
};

glyph_quantization parse_quantization(const std::string& quantization) {
    if (quantization == "Q1H") return glyph_quantization::Q1H;
    else if (quantization == "Q1V") return glyph_quantization::Q1V;
    else if (quantization == "Q2H") return glyph_quantization::Q2H;
    else if (quantization == "Q2V") return glyph_quantization::Q2V;
    else if (quantization == "Q4H") return glyph_quantization::Q4H;
    else if (quantization == "Q4V") return glyph_quantization::Q4V;
    else if (quantization == "Q8") return glyph_quantization::Q8;
    else if (quantization == "Q16RGB") return glyph_quantization::Q16_RGB;
    else if (quantization == "Q24RGB") return glyph_quantization::Q24_RGB;
    else if (quantization == "Q32RGBA") return glyph_quantization::Q32_RGBA;
    else {
        ASSERT(false, std::format("Unsupported quantization: {}", quantization));
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Illegal parameter count" << std::endl;
        exit(EXIT_FAILURE);
    }
    auto cfgs = load_configs(argv[1]);
    FT_Library ft_lib;
    ASSERT(FT_Init_FreeType(&ft_lib), "Cannot initialize Freetype library");
    byte_buffer data;
    std::vector<uint32_t> faces;
    for (int i = 0; i < cfgs.size(); ++i) {
        auto& cfg = cfgs[i];
        std::cout << std::format( "Processing config #{}: {} | {} | {}", i, cfg.font_path, cfg.font_name, cfg.font_height) << std::endl;
        FT_Face face;
        ASSERT(FT_New_Face(ft_lib, cfg.font_path.c_str(), 0, &face), std::format("Cannot load face {}", cfg.font_path));
        ASSERT(FT_Set_Pixel_Sizes(face, 0, cfg.font_height), std::format("Cannot set size {} for face {}", cfg.font_height, cfg.font_path));
        std::ranges::sort(cfg.characters.begin(), cfg.characters.end(), [](const auto a, const auto b) {
            return a < b;
        });
        faces.push_back(data.index());
        glyph_quantization quantization_type = parse_quantization(cfg.quantization);
        font_face_meta fm {
            .glyphs = static_cast<u32>(cfg.characters.size()),
            .face_id = static_cast<u32>(i),
            .quantization = quantization_type
        };
        data.append(fm);
        u32 glyph_index_base = data.index();
        data.reserve(sizeof(glyph_index) * cfg.characters.size());
        auto glyph_indices = data.get_array_view<glyph_index>(glyph_index_base, cfg.characters.size());
        for (size_t j = 0; j < cfg.characters.size(); ++j) {
            char32_t c = cfg.characters[j];
            std::cout << "Quantizing character U+" << static_cast<uint32_t>(c) << std::endl;
            FT_UInt glyph_index = FT_Get_Char_Index(face, c);
            ASSERT(glyph_index == 0, std::format("Character U+{} not exists in the font file {}", static_cast<uint32_t>(c), cfg.font_path));
            ASSERT(FT_Load_Glyph(face, glyph_index, FT_LOAD_RENDER | FT_LOAD_TARGET_NORMAL | FT_LOAD_NO_SVG), std::format("Cannot load Character U+{} in the font file {}", static_cast<uint32_t>(c), cfg.font_path))
            ASSERT(face->glyph->format != FT_GLYPH_FORMAT_BITMAP, std::format("Character U+{} was not rendered to a bitmap", static_cast<uint32_t>(c)));
            FT_Bitmap converted_bitmap{};
            const FT_Bitmap* bitmap = &face->glyph->bitmap;
            bool owns_converted_bitmap = false;
            if (bitmap->width != 0 && bitmap->rows != 0 && bitmap->pixel_mode != FT_PIXEL_MODE_GRAY) {
                ASSERT(FT_Bitmap_Convert(ft_lib, bitmap, &converted_bitmap, 1), std::format("Cannot convert Character U+{} to 8-bit grayscale", static_cast<uint32_t>(c)));
                bitmap = &converted_bitmap;
                owns_converted_bitmap = true;
            }
            FT_GlyphSlotRec normalized_glyph = *face->glyph;
            normalized_glyph.bitmap = *bitmap;
            glyph_indices[j].unicode = c;
            glyph_indices[j].offset = data.index();
            if (quantization_type == glyph_quantization::Q8) {
                data.append(Q8(c, &normalized_glyph, cfg.quantization_args));
            } else if (quantization_type <= glyph_quantization::Q4V) {
                data.append(Q1_2_4(c, &normalized_glyph, cfg.quantization_args, quantization_type));
            } else {
                ASSERT(false, std::format("Unsupported quantization: {}", cfg.quantization));
            }
            if (owns_converted_bitmap) {
                FT_Bitmap_Done(ft_lib, &converted_bitmap);
            }
        }
        FT_Done_Face(face);
    }
    std::ofstream binary_file("flushable.bin", std::ios::out | std::ios::binary);
    std::ofstream header_file("faces.h", std::ios::out | std::ios::binary);
    binary_file.write(reinterpret_cast<const char*>(&data[0]), data.index());
    std::string begin = "#pragma once\n";
    header_file.write(begin.c_str(), begin.size());
    for (int i = 0; i < cfgs.size(); ++i) {
        auto line = std::format("const static unsigned int Face_{}_{}px_Offset = {};\n", cfgs[i].font_name, cfgs[i].font_height, faces[i]);
        header_file.write(line.c_str(), line.size());
    }
    std::cout << "Generated successfully; flushable file is stored at flushable.bin, header file is stored at faces.h";
}
