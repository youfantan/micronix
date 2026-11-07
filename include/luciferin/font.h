#pragma once

#include "base.h"

namespace micronix::luciferin
{
    enum class glyph_quantization : u8 {
        Q1H,
        Q1V,
        Q2H,
        Q2V,
        Q4H,
        Q4V,
        Q8,
        Q16_RGB,
        Q24_RGB,
        Q32_RGBA
    };

#pragma pack(push, 1)
    struct glyph_meta {
        u32 unicode;
        u8 width;
        u8 height;
        u8 advance;
        i8 bearing_x;
        i8 bearing_y;
    };
#pragma pack(pop)

#pragma pack(push, 1)
    struct glyph_index {
        u32 unicode;
        u32 offset;

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
        u32 glyphs;
        u32 face_id;
        glyph_quantization quantization;
    };
#pragma pack(pop)

    static_assert(sizeof(glyph_meta) == 9);
    static_assert(sizeof(glyph_index) == 8);
    static_assert(sizeof(font_face_meta) == 9);

    glyph_meta* find_glyph(void* base, u32 face_base, u32 unicode);
}
