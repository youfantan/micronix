#pragma once

#include "../../base.h"

namespace micronix::luciferin
{
    template<typename color_format>
    concept is_color_format = requires(u32 v32, u8 v8, color_format cf, void* fb)
    {
        color_format(v8, v8, v8);
        color_format(v8);
        cf.data;
        color_format::get_buffer_bytes(v32);
        color_format::set_pixel(fb, v32, cf);
    };

    struct color_format_rgb565 {
        constexpr static u32 get_buffer_bytes(u32 pixels) {
            return pixels * 2;
        }

        constexpr static void set_pixel(void* framebuffer, u32 offset, color_format_rgb565 color) {
            auto* bytes = static_cast<u8*>(framebuffer);
            bytes[2 * offset] = color.data[0];
            bytes[2 * offset + 1] = color.data[1];
        }

        constexpr color_format_rgb565(u8 R, u8 G, u8 B) : data{} {
            const u16 value = static_cast<u16>(
                (static_cast<u16>(R & 0xf8u) << 8) |
                (static_cast<u16>(G & 0xfcu) << 3) |
                (static_cast<u16>(B) >> 3));
            data[0] = static_cast<u8>(value >> 8);
            data[1] = static_cast<u8>(value);
        }

        constexpr color_format_rgb565(u8 Gray) : data{} {
            const u8 level = static_cast<u8>(255 - Gray);
            const u16 value = static_cast<u16>(
                (static_cast<u16>(level & 0xf8u) << 8) |
                (static_cast<u16>(level & 0xfcu) << 3) |
                (static_cast<u16>(level) >> 3));
            data[0] = static_cast<u8>(value >> 8);
            data[1] = static_cast<u8>(value);
        }

        u8 data[2];
    };

    struct color_format_rgb24 {
        constexpr static u32 get_buffer_bytes(u32 pixels) {
            return pixels * 3;
        }

        constexpr static void set_pixel(void* framebuffer, u32 offset, color_format_rgb24 color) {
            auto* bytes = static_cast<u8*>(framebuffer);
            bytes[offset * 3] = color.data[0];
            bytes[offset * 3 + 1] = color.data[1];
            bytes[offset * 3 + 2] = color.data[2];
        }

        constexpr color_format_rgb24(u8 R, u8 G, u8 B) : data{ R, G, B } {}
        constexpr color_format_rgb24(u8 Gray) : data{ static_cast<u8>(255 - Gray), static_cast<u8>(255 - Gray), static_cast<u8>(255 - Gray) } {}

        u8 data[3];
    };
}
