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
#include <buffer.h>

#include FT_FREETYPE_H
#include FT_BITMAP_H

struct glyph_quantization {
    constexpr glyph_quantization(uint8_t v) : v(v) {
    }

    uint8_t bits() const {
        return 1 << (v & 0x7F);
    }

    bool vh() const {
        return v >> 7;
    }

    bool operator==(const glyph_quantization& other) const {
        return v == other.v;
    }

private:
    uint8_t v;
};

template <uint8_t bits, uint8_t vh>
constexpr glyph_quantization make_quantization_type() {
    static_assert(bits <= 0x7F);
    static_assert(vh <= 1);
    return {(vh << 7) | bits & 0x7F};
}

constexpr static glyph_quantization Q1V = make_quantization_type<0, 1>();
constexpr static glyph_quantization Q1H = make_quantization_type<0, 0>();
constexpr static glyph_quantization Q2V = make_quantization_type<1, 1>();
constexpr static glyph_quantization Q2H = make_quantization_type<1, 0>();
constexpr static glyph_quantization Q4V = make_quantization_type<2, 1>();
constexpr static glyph_quantization Q4H = make_quantization_type<2, 0>();
constexpr static glyph_quantization Q8_GRAY = make_quantization_type<3, 0>();
constexpr static glyph_quantization Q16_RGB = make_quantization_type<4, 0>();
constexpr static glyph_quantization Q24_RGB = make_quantization_type<4, 1>();
constexpr static glyph_quantization Q32_RGBA = make_quantization_type<5, 0>();

#pragma pack(push, 1)
struct glyph_meta {
    uint32_t unicode;
    uint8_t width;
    uint8_t height;
    uint8_t advance;
    int8_t bearing_x;
    int8_t bearing_y;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct glyph_index {
    uint32_t unicode;
    uint32_t offset;

    bool operator==(const glyph_index& other) const {
        return unicode == other.unicode;
    }

    bool operator<(const glyph_index& other) const {
        return unicode < other.unicode;
    }

    bool operator>(const glyph_index& other) const {
        return unicode > other.unicode;
    }
};
#pragma pack(pop)

#pragma pack(push, 1)
struct font_face_meta {
    uint32_t glyphs;
    uint32_t face_id;
    glyph_quantization quantization;
    uint8_t quantization_table[15]; // Levels 1..15; level 0 is implicitly zero.
};
#pragma pack(pop)

#define ASSERT(cond, msg) if (!(cond)) { std::cout << "Fatal at expression '" << #cond << "': " << msg << std::endl; exit(EXIT_FAILURE); }

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
        }
        else if ((first & 0xE0) == 0xC0) {
            cp = first & 0x1F;
            extra_bytes = 1;
        }
        else if ((first & 0xF0) == 0xE0) {
            cp = first & 0x0F;
            extra_bytes = 2;
        }
        else if ((first & 0xF8) == 0xF0) {
            cp = first & 0x07;
            extra_bytes = 3;
        }
        else {
            std::cout << "Invalid UTF-8 leading byte" << std::endl;
            exit(EXIT_FAILURE);
        }
        ASSERT(i + extra_bytes < input.size(), "Truncated UTF-8 sequence");
        for (size_t j = 1; j <= extra_bytes; ++j) {
            auto next = static_cast<uint8_t>(input[i + j]);
            ASSERT((next & 0xC0) == 0x80, "Invalid UTF-8 continuation byte");
            cp = (cp << 6) | (next & 0x3F);
        }
        constexpr char32_t minimumByLength[] = {
            0, 0, 0x80, 0x800, 0x10000
        };
        const size_t length = extra_bytes + 1;
        ASSERT(cp >= minimumByLength[length], "Overlong UTF-8 sequence");
        ASSERT(cp < 0xD800 || cp > 0xDFFF, "UTF-8 contains surrogate code point");
        ASSERT(cp <= 0x10FFFF, "Code point exceeds U+10FFFF");
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
        settings_stream >> config.font_path >> config.font_name >> config.quantization >> config.render_mode >> config.
            font_height;
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

template <typename T>
constexpr static T round_up(T n, T div) {
    return (n + div - 1) / div;
}

void validate_glyph_bitmap(char32_t unicode, FT_GlyphSlot glyph) {
    const auto& bmp = glyph->bitmap;
    ASSERT(bmp.width <= 255,
           std::format("Character U+{} glyph width '{}' is illegal", static_cast<uint32_t>(unicode), bmp.width));
    ASSERT(bmp.rows <= 255,
           std::format("Character U+{} glyph height '{}' is illegal", static_cast<uint32_t>(unicode), bmp.rows));
    ASSERT(bmp.pitch >= static_cast<int>(bmp.width),
           std::format("Character U+{} glyph pitch '{}' is illegal", static_cast<uint32_t>(unicode), bmp.pitch));
    ASSERT(bmp.width == 0 || bmp.rows == 0 || bmp.buffer != nullptr,
           std::format("Character U+{} glyph bitmap is empty", static_cast<uint32_t>(unicode)));
    ASSERT(bmp.width == 0 || bmp.rows == 0 || bmp.pixel_mode == FT_PIXEL_MODE_GRAY,
           std::format("Character U+{} glyph is not 8-bit grayscale", static_cast<uint32_t>(unicode)));
}

void validate_glyph_metrics(char32_t unicode, FT_GlyphSlot glyph) {
    const auto advance = glyph->advance.x >> 6;
    ASSERT(advance >= 0 && advance <= 255,
           std::format("Advance '{}' of glyph U+{} is out of range", advance, static_cast<uint32_t>(unicode)));
    ASSERT(glyph->bitmap_left >= -128 && glyph->bitmap_left <= 127,
           std::format("BearingX '{}' of glyph U+{} is out of range", glyph->bitmap_left, static_cast<uint32_t>(unicode)
           ));
    ASSERT(glyph->bitmap_top >= -128 && glyph->bitmap_top <= 127,
           std::format("BearingY '{}' of glyph U+{} is out of range", glyph->bitmap_top, static_cast<uint32_t>(unicode)
           ));
}

std::vector<int> parse_thresholds(const std::string& args, size_t count) {
    std::vector<int> thresholds(count);
    std::stringstream ss(args);
    for (size_t i = 0; i < count; ++i) {
        ASSERT(ss >> thresholds[i], std::format("Expected {} quantization thresholds", count));
        ASSERT(thresholds[i] > 0 && thresholds[i] < 255, "Illegal quantization argument");
        if (i != 0) {
            ASSERT(thresholds[i] > thresholds[i - 1], "Quantization thresholds must be strictly increasing");
        }
    }
    std::string trailing;
    ASSERT(!(ss >> trailing), std::format("Expected exactly {} quantization thresholds", count));
    return thresholds;
}

glyph_quantization parse_quantization_type(const std::string& type) {
    if (type == "Q1H") return Q1H;
    if (type == "Q1V") return Q1V;
    if (type == "Q2H") return Q2H;
    if (type == "Q2V") return Q2V;
    if (type == "Q4H") return Q4H;
    if (type == "Q4V") return Q4V;
    if (type == "Q8_GRAY") return Q8_GRAY;
    if (type == "Q16_RGB") return Q16_RGB;
    if (type == "Q24_RGB") return Q24_RGB;
    if (type == "Q32_RGBA") return Q32_RGBA;
    ASSERT(false, std::format("Unmatched quantization type: {}", type));
}

std::vector<uint8_t> make_glyph_meta(char32_t unicode, FT_GlyphSlot glyph, const std::vector<uint8_t>& bits) {
    validate_glyph_metrics(unicode, glyph);
    const auto& bmp = glyph->bitmap;
    glyph_meta glyph_meta{
        .unicode = static_cast<uint32_t>(unicode),
        .width = static_cast<uint8_t>(bmp.width),
        .height = static_cast<uint8_t>(bmp.rows),
        .advance = static_cast<uint8_t>(glyph->advance.x >> 6),
        .bearing_x = static_cast<int8_t>(glyph->bitmap_left),
        .bearing_y = static_cast<int8_t>(glyph->bitmap_top)
    };
    std::vector<uint8_t> data(sizeof(glyph_meta) + bits.size());
    std::memcpy(data.data(), &glyph_meta, sizeof(glyph_meta));
    if (!bits.empty()) std::memcpy(data.data() + sizeof(glyph_meta), bits.data(), bits.size());
    return data;
}

std::vector<uint8_t> qs1_2_4(char32_t unicode, FT_GlyphSlot glyph, const std::string& args, glyph_quantization quantization_type) {
    auto& bmp = glyph->bitmap;
    validate_glyph_bitmap(unicode, glyph);
    uint32_t bits_per_pixel = quantization_type.bits();
    bool vertical = quantization_type.vh();
    uint32_t pixels_per_byte = 8u / bits_per_pixel;
    uint32_t threshold_count = (1u << bits_per_pixel) - 1;
    auto thresholds = parse_thresholds(args, threshold_count);
    auto width = vertical ? bmp.width : round_up(bmp.width, pixels_per_byte);
    auto height = vertical ? round_up(bmp.rows, pixels_per_byte) : bmp.rows;
    std::vector<uint8_t> bits(width * height);
    auto sample = [](uint8_t pixel, const int* thresholds, int n) {
        uint8_t q = 0;
        for (int i = 0; i < n; ++i) {
            if (pixel < thresholds[i]) return q;
            ++q;
        }
        return q;
    };
    for (uint32_t y = 0; y < bmp.rows; ++y) {
        for (uint32_t x = 0; x < bmp.width; ++x) {
            uint8_t p = bmp.buffer[x + y * bmp.pitch];
            auto level = sample(p, thresholds.data(), static_cast<int>(thresholds.size()));
            uint32_t bx;
            uint32_t by;
            unsigned shift;
            if (vertical) {
                bx = x;
                by = y / pixels_per_byte;
                shift = (y % pixels_per_byte) * bits_per_pixel;
            }
            else {
                bx = x / pixels_per_byte;
                by = y;
                shift = (x % pixels_per_byte) * bits_per_pixel;
            }
            bits[bx + by * width] |= static_cast<uint8_t>(level << shift);
        }
    }
    return make_glyph_meta(unicode, glyph, bits);
}

std::vector<uint8_t> qs8(char32_t unicode, FT_GlyphSlot glyph, const std::string&) {
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

std::vector<std::pair<std::string, byte_buffer>> make_fonts(std::vector<quantization_config>& cfgs) {
    FT_Library ft_lib;
    ASSERT(FT_Init_FreeType(&ft_lib) == 0, "Cannot initialize Freetype library");
    std::vector<std::pair<std::string, byte_buffer>> result;
    for (int i = 0; i < cfgs.size(); ++i) {
        auto& cfg = cfgs[i];
        byte_buffer font_buffer;
        std::cout << std::format("Processing config #{}: {} | {} | {}", i, cfg.font_path, cfg.font_name,
                                 cfg.font_height) << std::endl;
        FT_Face face;
        ASSERT(FT_New_Face(ft_lib, cfg.font_path.c_str(), 0, &face) == 0, std::format("Cannot load face {}", cfg.font_path));
        ASSERT(FT_Set_Pixel_Sizes(face, 0, cfg.font_height) == 0, std::format("Cannot set size {} for face {}", cfg.font_height, cfg.font_path));
        std::ranges::sort(cfg.characters.begin(), cfg.characters.end(), [](const auto a, const auto b) {
            return a < b;
        });
        glyph_quantization quantization_type = parse_quantization_type(cfg.quantization);
        font_face_meta fm{
            .glyphs = static_cast<uint32_t>(cfg.characters.size()),
            .face_id = static_cast<uint32_t>(i),
            .quantization = quantization_type,
            .quantization_table = {}
        };
        if (quantization_type.bits() <= 4) {
            const uint32_t levels = (1u << quantization_type.bits()) - 1;
            parse_thresholds(cfg.quantization_args, levels);
            for (uint32_t level = 1; level <= levels; ++level) {
                fm.quantization_table[level - 1] = static_cast<uint8_t>(level * 255 / levels);
            }
        }
        font_buffer.append(fm);
        uint8_t glyph_index_base = font_buffer.index();
        font_buffer.forward(sizeof(glyph_index) * cfg.characters.size());
        auto glyph_indices = font_buffer.get_array_view<glyph_index>(glyph_index_base, cfg.characters.size());
        uint32_t rel_offset = 0;
        for (size_t j = 0; j < cfg.characters.size(); ++j) {
            char32_t c = cfg.characters[j];
            std::cout << "Quantizing character U+" << static_cast<uint32_t>(c) << std::endl;
            FT_UInt glyph_index = FT_Get_Char_Index(face, c);
            ASSERT(glyph_index != 0, std::format("Character U+{} not exists in the font file {}", static_cast<uint32_t>(c), cfg.font_path));
            ASSERT(FT_Load_Glyph(face, glyph_index, FT_LOAD_RENDER | FT_LOAD_TARGET_NORMAL | FT_LOAD_NO_SVG) == 0, std::format("Cannot load Character U+{} in the font file {}", static_cast<uint32_t>(c), cfg.font_path));
            ASSERT(face->glyph->format == FT_GLYPH_FORMAT_BITMAP, std::format("Character U+{} was not rendered to a bitmap", static_cast<uint32_t>(c)));
            FT_Bitmap converted_bitmap{};
            const FT_Bitmap* bitmap = &face->glyph->bitmap;
            bool owns_converted_bitmap = false;
            if (bitmap->width != 0 && bitmap->rows != 0 && bitmap->pixel_mode != FT_PIXEL_MODE_GRAY) {
                ASSERT(FT_Bitmap_Convert(ft_lib, bitmap, &converted_bitmap, 1) == 0,
                       std::format("Cannot convert Character U+{} to 8-bit grayscale", static_cast<uint32_t>(c)));
                bitmap = &converted_bitmap;
                owns_converted_bitmap = true;
            }
            FT_GlyphSlotRec normalized_glyph = *face->glyph;
            normalized_glyph.bitmap = *bitmap;
            glyph_indices[j].unicode = c;
            glyph_indices[j].offset = rel_offset;
            if (quantization_type == Q8_GRAY) {
                auto bits = qs8(c, &normalized_glyph, cfg.quantization_args);
                rel_offset += bits.size();
                font_buffer.append(bits);
            }
            else if (quantization_type.bits() <= 4) {
                auto bits = qs1_2_4(c, &normalized_glyph, cfg.quantization_args, quantization_type);
                rel_offset += bits.size();
                font_buffer.append(bits);
            }
            else {
                ASSERT(false, std::format("Unsupported quantization: {}", cfg.quantization));
            }
            if (owns_converted_bitmap) {
                FT_Bitmap_Done(ft_lib, &converted_bitmap);
            }
        }
        result.emplace_back(std::format("Font_{}_{}px", cfg.font_name, cfg.font_height), std::move(font_buffer));
        FT_Done_Face(face);
    }
    return result;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Illegal parameter count" << std::endl;
        exit(EXIT_FAILURE);
    }
    auto cfgs = load_configs(argv[1]);
    auto fonts = make_fonts(cfgs);
    for (auto& f : fonts) {
        std::ofstream ofile(f.first + ".bin", std::ios::out | std::ios::binary);
        ASSERT(ofile.good(), "Cannot open output file");
        ofile.write(reinterpret_cast<const char*>(&f.second[0]), f.second.index());
        std::cout << f.first << ".bin is saved" << std::endl;
    }
    return 0;
}
