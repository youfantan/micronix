#pragma once

#include "../../base.h"
#include "../../utils/containers.h"
#include "../../utils/string.h"
#include "../rofs/rofs.h"
namespace micronix::luciferin
{
    struct glyph_quantization {
        constexpr glyph_quantization(u8 v) : v(v) {}

        u8 bits() const {
            return 1 << (v & 0x7F);
        }

        bool vh() const {
            return v >> 7;
        }

        bool operator==(const glyph_quantization& other) const {
            return v == other.v;
        }
    private:
        u8 v;
    };

    template<u8 bits, u8 vh>
    constexpr glyph_quantization make_quantization_type() {
        static_assert(bits <= 0x7F);
        static_assert(vh <= 1);
        return { (vh << 7) | bits & 0x7F };
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
        u8 quantization_table[15]; // Levels 1..15; level 0 is implicitly zero.
    };
#pragma pack(pop)

    static_assert(sizeof(glyph_meta) == 9);
    static_assert(sizeof(glyph_index) == 8);
    static_assert(sizeof(font_face_meta) == 24);

    class font {
        const font_face_meta* meta_;
    public:
        font(const font_face_meta* meta) : meta_(meta) {}
        font(font& other) = default;
        font(font&& other) = default;
        font& operator=(font& other) = default;
        font& operator=(font&& other) = default;

        result<const glyph_meta*> find_glyph(char32_t unicode) const {
            auto* indices = reinterpret_cast<const glyph_index*>(meta_ + 1);
            auto found = binary_search(indices, meta_->glyphs, { static_cast<u32>(unicode) });
            if (found) {
                auto* glyph_data = reinterpret_cast<const u8*>(meta_ + 1) + meta_->glyphs * sizeof(glyph_index);
                return reinterpret_cast<const glyph_meta*>(glyph_data + found->offset);
            }
            return failed;
        }

        const font_face_meta* get_meta() const {
            return meta_;
        }

        const font_face_meta* operator->() const {
            return meta_;
        }
    };

    inline result<font> find_font(const utf8_string_literal& font_name) {
        using namespace micronix::rofs;
        const auto meta = rofs_find_by_string<font_face_meta>(font_name);
        if (!meta.success()) {
            return failed;
        }
        return font{ meta.get() };
    }
}
