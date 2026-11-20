#pragma once

#include "../include/base.h"
#include "../include/kernel/cron.h"
#include "../include/peripherals/spi.h"
#include "../include/peripherals/gpio.h"
#include "../include/subsystem/luciferin/color.h"
#include "../include/utils/algorithms.h"

namespace micronix::modules {

    struct st7735s_cfg {
        struct _init_cmds {
            u8 slpout[1] { 0x11 }; // Sleep out
            u8 noron[1] { 0x13 }; // Normal display on
            u8 madctl[2] { 0x36, 0x00 }; // Set position mapping
            u8 colmod[2] { 0x3A, 0x05 }; // Set color mode to RGB565
            u8 lut[129] { 0x2D }; // Set RGB565 to RGB666 LUT
            u8 caset[2] { 0x2A, 0x00 }; // Set width
            u8 raset[2] { 0x2B, 0x00 }; // Set height
            u8 dispon[1] { 0x29 };
        } init_cmds;

        constexpr st7735s_cfg(u8 width, u8 height) {
            init_cmds.caset[1] = width;
            init_cmds.raset[1] = height;
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
            init_cmds.madctl[1] |= 0x20;
            swap(init_cmds.caset[1], init_cmds.raset[1]);
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
    class st7735s {
    public:
        st7735s() {
            blk::reset();
            if constexpr(!rst::is_null) {
                rst::reset();
                kernel::timer_sleep(1000);
                rst::set();
            }
            send_command(cfg.init_cmds.slpout, sizeof(cfg.init_cmds.slpout));
            kernel::timer_sleep(120000);
            send_command(cfg.init_cmds.noron, sizeof(cfg.init_cmds.noron));
            send_command(cfg.init_cmds.madctl, sizeof(cfg.init_cmds.madctl));
            send_command(cfg.init_cmds.colmod, sizeof(cfg.init_cmds.colmod));
            send_command(cfg.init_cmds.lut, sizeof(cfg.init_cmds.lut));
            send_command(cfg.init_cmds.caset, sizeof(cfg.init_cmds.caset));
            send_command(cfg.init_cmds.raset, sizeof(cfg.init_cmds.raset));
            send_command(0x2C, 1);
            u8 black[2] = { 0x00, 0x00 };
            for (u32 i = 0; i < cfg.init_cmds.caset[1] * cfg.init_cmds.raset[1]; ++i) {
                send_data(black, 2);
            }
            send_command(cfg.init_cmds.dispon, sizeof(cfg.init_cmds.dispon));
            if constexpr(!blk::is_null) {
                blk::set();
            }
        }

        void send_command(const u8* cmd, u32 len) {
            dc::reset();
            cs::reset();
            spi::batched_write_blocking(cmd, len);
            cs::set();
        }

        void send_data(const u8* data, u32 len) {
            dc::set();
            cs::reset();
            spi::batched_write_blocking(data, len);
            cs::set();
        }
    };

}
