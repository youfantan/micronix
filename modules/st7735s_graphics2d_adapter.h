#pragma once

#include "../include/base.h"
#include "../include/kernel/cron.h"
#include "../include/peripherals/spi.h"
#include "../include/peripherals/gpio.h"
#include "../include/subsystem/luciferin/color.h"
#include "../include/utils/algorithms.h"

namespace micronix::modules {

    struct st7735s_cfg {
        u8 width;
        u8 height;

        struct _init_cmds {
            u8 slpout[1] { 0x11 }; // Sleep out
            u8 noron[1] { 0x13 }; // Normal display on
            u8 madctl[2] { 0x36, 0x00 }; // Set position mapping
            u8 colmod[2] { 0x3A, 0x05 }; // Set color mode to RGB565
            u8 lut[129] { 0x2D }; // Set RGB565 to RGB666 LUT
            u8 dispon[1] { 0x29 };
            u8 ramwr[1] { 0x2C };
        } init_cmds;

        constexpr st7735s_cfg(u8 width, u8 height) : width(width), height(height) {
            for (unsigned i = 0; i < 32; ++i) {
                uint8_t value = (i << 1) | (i >> 4);
                init_cmds.lut[1 + i] = value;
                init_cmds.lut[97 + i] = value;
            }
            for (unsigned i = 0; i < 64; ++i) {
                init_cmds.lut[33 + i] = i;
            }
        }

        constexpr void x_mirror() {
            init_cmds.madctl[1] |= 0x80;
        }

        constexpr void y_mirror() {
            init_cmds.madctl[1] |= 0x40;
        }

        constexpr void xy_exchange() {
            if (!(init_cmds.madctl[1] & 0x20)) {
                init_cmds.madctl[1] |= 0x20;
                swap(width, height);
            }
        }

        constexpr void set_bgr() {
            init_cmds.madctl[1] |= 0x08;
        }

        constexpr u8* lut() {
            return &init_cmds.lut[1];
        }
    };



    template<typename spi, typename cs, typename dc, typename sda, typename sck, typename rst, typename blk, st7735s_cfg cfg>
    requires peripherals::is_spi<spi> && peripherals::allow_unnull_gpio<cs> && peripherals::allow_unnull_gpio<dc> &&
        peripherals::allow_unnull_gpio<sda> && peripherals::allow_unnull_gpio<sck> && peripherals::allow_null_gpio<rst> &&
        peripherals::allow_null_gpio<blk>
    struct st7735s_graphics2d_adapter {
        using context = struct st7735s_graphics2d_context {
            using color_format = luciferin::color_format_rgb565;
            constexpr static u32 Width = cfg.width;
            constexpr static u32 Height = cfg.height;
        };

        constexpr static u32 FrameBufferSize = context::color_format::get_buffer_bytes(context::Width * context::Height);
        static_assert(cfg.width > 0 && cfg.height > 0);

        constexpr static void initialize() {
            cs::set();
            if constexpr (!blk::is_null) {
                blk::reset();
            }
            if constexpr(!rst::is_null) {
                rst::reset();
                kernel::timer_sleep(1000);
                rst::set();
            }
            kernel::timer_sleep(120000);
            send_command(cfg.init_cmds.slpout);
            kernel::timer_sleep(120000);
            send_command(cfg.init_cmds.noron);
            send_command(cfg.init_cmds.madctl);
            send_command(cfg.init_cmds.colmod);
            send_command(cfg.init_cmds.lut);
            constexpr u8 caset[] { 0x2A, 0, 0, 0, static_cast<u8>(cfg.width - 1) };
            constexpr u8 raset[] { 0x2B, 0, 0, 0, static_cast<u8>(cfg.height - 1) };
            send_command(caset);
            send_command(raset);
            present();
            send_command(cfg.init_cmds.dispon);
            if constexpr(!blk::is_null) {
                blk::set();
            }
        }

        constexpr static void present() {
            send_command(cfg.init_cmds.ramwr);
            send_data(framebuffer, FrameBufferSize);
        }

        constexpr static void destroy() {

        }

        template<u32 N>
        constexpr static void send_command(const u8 (&command)[N]) {
            send_command(command, 1);
            if constexpr (N > 1) {
                send_data(command + 1, N - 1);
            }
        }

        constexpr static void send_command(const u8* cmd, u32 len) {
            dc::reset();
            spi::template select<cs>();
            spi::batched_write_blocking(cmd, len);
            spi::template unselect<cs>();
        }

        constexpr static void send_data(const u8* data, u32 len) {
            dc::set();
            spi::template select<cs>();
            spi::batched_write_blocking(data, len);
            spi::template unselect<cs>();
        }

        static void* get_framebuffer() {
            return framebuffer;
        }

    private:
        inline static u8 framebuffer[FrameBufferSize];
    };

}
