#pragma once

#include "base.h"

namespace micronix::luciferin
{
    struct ColorFormatRGB565 {
        constexpr static u32 get_buffer_bytes(u32 width, u32 height) {
            return width * height * 2;
        }

        static void set_pixel(void* framebuffer, u32 offset, ColorFormatRGB565 color) {
            auto* bytes = static_cast<u8*>(framebuffer);
            bytes[2 * offset] = color.data[0];
            bytes[2 * offset + 1] = color.data[1];
        }

        u8 data[2];

        ColorFormatRGB565(u8 R, u8 G, u8 B) {

        }

        ColorFormatRGB565(u8 Gray) {

        }
    };

    struct ColorFormatRGB24 {
        constexpr static u32 get_buffer_bytes(u32 width, u32 height) {
            return width * height * 3;
        }

        static void set_pixel(void* framebuffer, u32 offset, ColorFormatRGB24 color) {
            auto* bytes = static_cast<u8*>(framebuffer);
            bytes[offset * 3] = color.data[0];
            bytes[offset * 3 + 1] = color.data[1];
            bytes[offset * 3 + 2] = color.data[2];
        }

        u8 data[3];

        ColorFormatRGB24(u8 R, u8 G, u8 B) : data{ R, G, B } {

        }

        ColorFormatRGB24(u8 Gray) : data{ static_cast<u8>(255 - Gray), static_cast<u8>(255 - Gray), static_cast<u8>(255 - Gray) } {

        }
    };
}