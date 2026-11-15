#pragma once

#include "../include/base.h"
#include "../include/kernel/cron.h"
#include "../include/peripherals/spi.h"
#include "../include/peripherals/gpio.h"
#include "../include/subsystem/luciferin/color.h"

namespace micronix::modules {
    struct st7735s_init_cmds {
        constexpr static u8 frame_rate[] { 0x01, 0x2c, 0x2d };
        constexpr static u8 frame_rate_3[] { 0x01, 0x2c, 0x2d, 0x01, 0x2c, 0x2d };
        constexpr static u8 inversion_control[] { 0x07 };
        constexpr static u8 power_control_1[] { 0xa2, 0x02, 0x84 };
        constexpr static u8 power_control_2[] { 0xc5 };
        constexpr static u8 power_control_3[] { 0x0a, 0x00 };
        constexpr static u8 power_control_4[] { 0x8a, 0x2a };
        constexpr static u8 power_control_5[] { 0x8a, 0xee };
        // Legacy ST7735 parameter set; PWCTR6 is not an ST7735S command.
        constexpr static u8 power_control_6[] { 0x0a, 0x82, 0x27, 0x00 };
        constexpr static u8 vcom[] { 0x0e };
        constexpr static u8 gamma_positive[] {
            0x02, 0x1c, 0x07, 0x12, 0x37, 0x32, 0x29, 0x2d,
            0x29, 0x25, 0x2b, 0x39, 0x00, 0x01, 0x03, 0x10,
        };
        static constexpr u8 gamma_negative[] {
            0x03, 0x1d, 0x07, 0x06, 0x2e, 0x2c, 0x29, 0x2d,
            0x2e, 0x2e, 0x37, 0x3f, 0x00, 0x00, 0x02, 0x10,
        };
        static constexpr u8 rgb565[] { 0x05 };
    };

    struct st7735s_cfg {
        u32 width;
        u32 height;
        u32 x_offset { 0 };
        u32 y_offset { 0 };
        u8 madctl { 0 };
        bool inverted { false };
    };

    template<typename spi, typename gpio_cs, typename gpio_blk, typename gpio_rst, typename gpio_dc, st7735s_cfg cfg, typename init_cmds = st7735s_init_cmds>
    requires
        peripherals::is_spi<spi> &&
        peripherals::allow_unnull_gpio<gpio_cs> &&
        peripherals::allow_null_gpio<gpio_blk> &&
        peripherals::allow_null_gpio<gpio_rst> &&
        peripherals::allow_unnull_gpio<gpio_dc>
    struct st7735s {
        constexpr static u32 column_count = (cfg.madctl & 0x20) ? 162 : 132;
        constexpr static u32 row_count = (cfg.madctl & 0x20) ? 132 : 162;
        static_assert(cfg.width > 0 && cfg.width <= column_count);
        static_assert(cfg.height > 0 && cfg.height <= row_count);
        static_assert(cfg.x_offset <= column_count - cfg.width);
        static_assert(cfg.y_offset <= row_count - cfg.height);

        struct context {
            constexpr static u32 width = cfg.width;
            constexpr static u32 height = cfg.height;
            constexpr static u32 Width = width;
            constexpr static u32 Height = height;
            using color_format = luciferin::color_format_rgb565;
        };

        struct adapter {
            using context = context;

            static void initialize() {
                if (initialized_) return;
                gpio_cs::set();
                gpio_dc::set();
                if constexpr (!gpio_blk::is_null) {
                    gpio_blk::reset();
                }
                if constexpr (!gpio_rst::is_null) {
                    gpio_rst::set();
                    kernel::timer_sleep(1000);
                    gpio_rst::reset();
                    kernel::timer_sleep(10000);
                    gpio_rst::set();
                    kernel::timer_sleep(120000);
                }
                initialized_ = true;

                send_cmd(0x01); // Software reset
                kernel::timer_sleep(120000);
                send_cmd(0x11);
                kernel::timer_sleep(120000);
                u8 madctl = cfg.madctl;
                send_cmd(0xb1, init_cmds::frame_rate);
                send_cmd(0xb2, init_cmds::frame_rate);
                send_cmd(0xb3, init_cmds::frame_rate_3);
                send_cmd(0xb4, init_cmds::inversion_control);
                send_cmd(0xc0, init_cmds::power_control_1);
                send_cmd(0xc1, init_cmds::power_control_2);
                send_cmd(0xc2, init_cmds::power_control_3);
                send_cmd(0xc3, init_cmds::power_control_4);
                send_cmd(0xc4, init_cmds::power_control_5);
                send_cmd(0xc5, init_cmds::vcom);
                send_cmd(0xe0, init_cmds::gamma_positive);
                send_cmd(0xe1, init_cmds::gamma_negative);
                send_cmd(0x3a, init_cmds::rgb565);
                send_cmd(0x36, &madctl, 1);
                send_cmd(cfg.inverted ? 0x21 : 0x20);
                send_cmd(0x13);
                kernel::timer_sleep(10000);
                send_cmd(0x29);
                kernel::timer_sleep(100000);
                if constexpr (!gpio_blk::is_null) gpio_blk::set();
            }

            static void present(void* framebuffer) {
                if (!initialized_ || !framebuffer) {
                    //TODO: raise error here
                    return;
                }
                set_window();
                send_cmd(0x2c);
                send_data(static_cast<const u8*>(framebuffer), context::color_format::get_buffer_bytes(cfg.width, cfg.height));
            }

            static void destroy() {
                if (!initialized_) return;
                if constexpr (!gpio_blk::is_null) gpio_blk::reset();
                send_cmd(0x28); // DISPOFF
                send_cmd(0x10); // SLPIN
                kernel::timer_sleep(120000);
                gpio_cs::set();
                gpio_dc::set();
                if constexpr (!gpio_rst::is_null) {
                    gpio_rst::reset();
                    gpio_rst::destory();
                }
                if constexpr (!gpio_blk::is_null) gpio_blk::destory();
                gpio_dc::destory();
                gpio_cs::destory();
                initialized_ = false;
            }

        };

    private:
        inline static bool initialized_ = false;

        static void send_cmd(u8 cmd, const u8* data, u32 len) {
            gpio_dc::reset();
            gpio_cs::reset();
            spi::batch_write(&cmd, 1);
            if (len != 0) {
                gpio_dc::set();
                spi::batch_write(data, len);
            }
            gpio_cs::set();
        }

        static void send_cmd(u8 cmd) {
            return send_cmd(cmd, nullptr, 0);
        }

        template<u32 N>
        static void send_cmd(u8 cmd, const u8 (&data)[N]) {
            return send_cmd(cmd, data, N);
        }

        static void send_data(const u8* data, u32 len) {
            gpio_dc::set();
            gpio_cs::reset();
            spi::batch_write(data, len);
            gpio_cs::set();
        }

        static void set_window() {
            constexpr u32 x_end = cfg.x_offset + cfg.width - 1;
            constexpr u32 y_end = cfg.y_offset + cfg.height - 1;
            constexpr u8 columns[] {
                static_cast<u8>(cfg.x_offset >> 8), static_cast<u8>(cfg.x_offset),
                static_cast<u8>(x_end >> 8), static_cast<u8>(x_end)
            };
            constexpr u8 rows[] {
                static_cast<u8>(cfg.y_offset >> 8), static_cast<u8>(cfg.y_offset),
                static_cast<u8>(y_end >> 8), static_cast<u8>(y_end)
            };
            return send_cmd(0x2a, columns) && send_cmd(0x2b, rows);
        }
    };

}
