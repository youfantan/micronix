#include "platform.h"

#include <subsystem/rofs/rofs.h>
#include <subsystem/luciferin/font.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

extern "C" {
    u32 _flash_rofs_imgbase[(ROFS_ImageSize + sizeof(u32) - 1) / sizeof(u32)] {};

    void memzero(void* ptr, u32 size) { std::memset(ptr, 0, size); }
    void memcopy(void* dest, const void* src, u32 size) { std::memcpy(dest, src, size); }
}

namespace micronix::kernel {
    void* slab_alloc(u32 size) { return std::malloc(size); }
    void slab_free(void* ptr) { std::free(ptr); }
}

namespace micronix::simulator {
    namespace {
        void require(bool condition, const char* message) {
            if (!condition) {
                std::cout << message << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        void validate_font(const rofs::rofs_entry& entry) {
            using namespace luciferin;
            require(entry.size >= sizeof(font_face_meta), "ROFS: truncated font metadata");
            const auto* bytes = reinterpret_cast<const u8*>(ROFS_ImageBase) + entry.offset;
            const auto* face = reinterpret_cast<const font_face_meta*>(bytes);
            require(face->glyphs > 0 && face->glyphs <=
                (entry.size - sizeof(font_face_meta)) / sizeof(glyph_index),
                "ROFS: invalid font index size");
            const u8 quantization = bytes[8];
            require((quantization & 0x7f) <= 3, "ROFS: unsupported font quantization");
            const u32 bits = face->quantization.bits();
            const u32 data_offset = sizeof(font_face_meta) + face->glyphs * sizeof(glyph_index);
            const u32 data_size = entry.size - data_offset;
            const auto* indices = reinterpret_cast<const glyph_index*>(face + 1);
            for (u32 i = 0; i < face->glyphs; ++i) {
                require(i == 0 || indices[i - 1].unicode < indices[i].unicode,
                    "ROFS: font indices must be sorted and unique");
                require(indices[i].offset <= data_size &&
                    data_size - indices[i].offset >= sizeof(glyph_meta),
                    "ROFS: glyph metadata outside font");
                const auto* glyph = reinterpret_cast<const glyph_meta*>(bytes + data_offset + indices[i].offset);
                require(glyph->unicode == indices[i].unicode, "ROFS: glyph index mismatch");
                const u32 bitmap_size = face->quantization.vh()
                    ? ((glyph->height * bits + 7) / 8) * glyph->width
                    : ((glyph->width * bits + 7) / 8) * glyph->height;
                require(bitmap_size <= data_size - indices[i].offset - sizeof(glyph_meta),
                    "ROFS: glyph bitmap outside font");
            }
        }
    }

    void load_rofs_image(const char* path) {
        std::ifstream image(path, std::ios::binary | std::ios::ate);
        if (!image) {
            std::cout << std::string("Cannot open ROFS image: ") + path << std::endl;
            exit(EXIT_FAILURE);
        }
        require(image.tellg() == static_cast<std::streamoff>(ROFS_ImageSize),
            "ROFS image size differs from include/config/rofs_conf.h");
        image.seekg(0);
        require(static_cast<bool>(image.read(reinterpret_cast<char*>(_flash_rofs_imgbase), ROFS_ImageSize)),
            "Cannot read complete ROFS image");

        using namespace rofs;
        static_assert(ROFS_ImageSize >= sizeof(rofs_header));
        static_assert(ROFS_Entries <= (ROFS_ImageSize - sizeof(rofs_header)) / sizeof(rofs_entry));
        const auto* header = reinterpret_cast<const rofs_header*>(ROFS_ImageBase);
        require(header->version == 1, "Unsupported ROFS image version");
        const auto* entries = reinterpret_cast<const rofs_entry*>(header + 1);
        constexpr u32 data_begin = sizeof(rofs_header) + ROFS_Entries * sizeof(rofs_entry);
        for (u32 i = 0; i < ROFS_Entries; ++i) {
            const auto& entry = entries[i];
            require(i == 0 || entry > entries[i - 1], "ROFS keys must be sorted and unique");
            require(entry.offset >= data_begin && entry.offset <= ROFS_ImageSize &&
                entry.size <= ROFS_ImageSize - entry.offset, "ROFS entry outside image");
            if (std::memcmp(entry.key, "Font_", 5) == 0) validate_font(entry);
        }
    }
}
