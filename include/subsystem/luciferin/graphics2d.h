#pragma once

#include "../../base.h"
#include "font.h"
#include "../../utils/string.h"

namespace micronix::luciferin
{
    template<typename adapter>
    class graphics2d {
        using context = typename adapter::context;
        using format = typename context::color_format;

        void* framebuffer_;
        void* fonts_base_;

    public:
        graphics2d(void* framebuffer, void* fonts_base) : framebuffer_(framebuffer), fonts_base_(fonts_base) {
            adapter::initialize();
        }

        constexpr static u32 get_framebuffer_size() {
            return format::get_buffer_bytes(context::Width, context::Height);
        }

        void draw_pixel(u32 x, u32 y, format cl) {
#ifndef NDEBUG
            if (x >= context::Width || y >= context::Height) {
                //TODO: raise error here
                return;
            }
#endif
            format::set_pixel(framebuffer_, x + y * context::Width, cl);
        }

        void draw_string(i32 x, i32 y, const font& font, const char32_t* unicodes, u32 len) const {
            auto draw = &draw_glyph_q1_2_4;
            if (font->quantization.bits() == 8) {
                draw = &draw_glyph_q8;
            }
            for (u32 i = 0; i < len; ++i) {
                char32_t u = unicodes[i];
                auto glyph = font.find_glyph(u);
                if (!glyph) return; //TODO: raise error here
                draw(framebuffer_, x, y, glyph, font);
                x += glyph->advance;
            }
        }

        void draw_string(i32 x, i32 y, const font& font, const utf32_string& string) {
            draw_string(x, y, font, string.str(), string.len());
        }

        void draw_string(i32 x, i32 y, const font& font, const utf32_string_literal& literal) {
            draw_string(x, y, font, literal.str(), literal.len());
        }

        void present() {
            adapter::present(framebuffer_);
        }

        ~graphics2d() {
            adapter::destroy();
        }

    private:
        static bool draw_glyph_q1_2_4(void* fb, i32 base_x, i32 base_y, const glyph_meta* glyph, const font& font) {
            u32 bits = font->quantization.bits();
            u8 bits_mask = 0xFF >> (8 - bits);
            bool vh = font->quantization.vh();
            const u8* data = reinterpret_cast<const u8*>(glyph + 1);
            base_x += glyph->bearing_x;
            base_y -= glyph->bearing_y;
            if (base_x < 0 || base_y < 0) return false;
            if (base_x + glyph->width > context::Width || base_y + glyph->height > context::Height) return false;
            u32 stride = (glyph->width * bits + 7) / 8;
            auto qs_h = [&](u32 x, u32 y) {
                u32 ix = x * bits / 8;
                u32 bx = x * bits % 8;
                return (data[y * stride + ix] >> bx) & bits_mask;
            };
            auto qs_v = [&](u32 x, u32 y) {
                u32 iy = y * bits / 8;
                u32 by = y * bits % 8;
                return (data[iy * glyph->width + x] >> by) & bits_mask;
            };
            for (u32 y = 0; y < glyph->height; ++y) {
                for (u32 x = 0; x < glyph->width; ++x) {
                    auto level = vh ? qs_v(x, y) : qs_h(x, y);
                    u8 gray = level ? font->quantization_table[level - 1] : 0;
                    format::set_pixel(fb, base_x + x + (base_y + y) * context::Width, format(gray));
                }
            }
            return true;
        }


        static bool draw_glyph_q8(void* fb, i32 base_x, i32 base_y, const glyph_meta* glyph, const font& font) {
            base_x += glyph->bearing_x;
            base_y -= glyph->bearing_y;
            const u8* data = reinterpret_cast<const u8*>(glyph + 1);
            if (base_x < 0 || base_y < 0) return false;
            if (base_x + glyph->width > context::Width || base_y + glyph->height > context::Height) return false;
            for (u32 y = 0; y < glyph->height; ++y) {
                for (u32 x = 0; x < glyph->width; ++x) {
                    format::set_pixel(fb, base_x + x + (base_y + y) * context::Width, format(data[x + y * glyph->width]));
                }
            }
            return true;
        }
    };
}
