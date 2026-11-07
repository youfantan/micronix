#pragma once

#include "base.h"

namespace micronix::luciferin
{
    template<typename Adapter>
    class graphics2d {
        using Context = Adapter::Context;
        using ColorFormat = Context::ColorFormat;

        void* framebuffer_;

    public:
        graphics2d(void* framebuffer) : framebuffer_(framebuffer) {
            Adapter::initialize();
        }

        constexpr static u32 get_framebuffer_size() {
            return Context::ColorFormat::get_buffer_bytes(Context::Width, Context::Height);
        }

        void draw_pixel(u32 x, u32 y, Adapter::Context::ColorFormat cl) {
#ifndef NDEBUG
            if (x > Context::Width || y > Context::Height) {
                Adapter::fallback("DrawPixel: Out of bounds");
            }
#endif
            ColorFormat::set_pixel(framebuffer_, x + y * Context::Width, cl);
        }

        void draw_string(u32 x, u32 y) {

        }

        void present() {
            Adapter::present(framebuffer_);
        }

        ~graphics2d() {
            Adapter::destroy();
        }
    };
}
