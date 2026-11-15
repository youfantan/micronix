#pragma once

#include "../../base.h"

namespace micronix::luciferin
{
    struct color_format_rgb565 {
        constexpr static u32 get_buffer_bytes(u32 width, u32 height) {
            return width * height * 2;
        }

        constexpr static u16 encode(u8 R, u8 G, u8 B) {
            return static_cast<u16>(
                (static_cast<u16>(R & 0xf8u) << 8) |
                (static_cast<u16>(G & 0xfcu) << 3) |
                (static_cast<u16>(B) >> 3));
        }

        static void set_pixel(void* framebuffer, u32 offset, color_format_rgb565 color) {
            auto* bytes = static_cast<u8*>(framebuffer);
            bytes[2 * offset] = color.data[0];
            bytes[2 * offset + 1] = color.data[1];
        }

        u8 data[2];

        color_format_rgb565(u8 R, u8 G, u8 B) {
            const u16 value = encode(R, G, B);
            data[0] = static_cast<u8>(value >> 8);
            data[1] = static_cast<u8>(value);
        }

        color_format_rgb565(u8 Gray) {
            const u8 level = static_cast<u8>(255 - Gray);
            const u16 value = encode(level, level, level);
            data[0] = static_cast<u8>(value >> 8);
            data[1] = static_cast<u8>(value);
        }
    };

    struct color_format_rgb24 {
        constexpr static u32 get_buffer_bytes(u32 width, u32 height) {
            return width * height * 3;
        }

        static void set_pixel(void* framebuffer, u32 offset, color_format_rgb24 color) {
            auto* bytes = static_cast<u8*>(framebuffer);
            bytes[offset * 3] = color.data[0];
            bytes[offset * 3 + 1] = color.data[1];
            bytes[offset * 3 + 2] = color.data[2];
        }

        u8 data[3];

        color_format_rgb24(u8 R, u8 G, u8 B) : data{ R, G, B } {

        }

        color_format_rgb24(u8 Gray) : data{ static_cast<u8>(255 - Gray), static_cast<u8>(255 - Gray), static_cast<u8>(255 - Gray) } {

        }
    };
}
