#include <base.h>
#include <rp2040/peripherals/gpio.h>
#include <rp2040/peripherals/spi.h>
#include <rp2040/peripherals/timer.h>
#include "../modules/st7735s_graphics2d_adapter.h"
#include <subsystem/luciferin/graphics2d.h>
void app_main() {
    using namespace micronix::peripherals;
    using namespace micronix::modules;
    using namespace micronix::luciferin;
    using namespace micronix::devices::rp2040;

    constexpr static gpio_init_cfg direct_pp = {
        .type = gpio_init_cfg::_type::output_pp,
        .pupd = gpio_init_cfg::_pupd::floating,
        .direct = true,
        .af = 5
    };
    using st7735s_blk = gpio6<direct_pp>;
    using st7735s_cs = gpio7<direct_pp>;
    using st7735s_dc = gpio8<direct_pp>;
    using st7735s_rst = gpio9<direct_pp>;
    using st7735s_sck = gpio10<gpio_init_cfg{
        .type = gpio_init_cfg::_type::output_pp,
        .pupd = gpio_init_cfg::_pupd::floating,
        .direct = false,
        .af = 1
    }>;
    using st7735s_sda = gpio11<gpio_init_cfg{
        .type = gpio_init_cfg::_type::output_pp,
        .pupd = gpio_init_cfg::_pupd::floating,
        .direct = false,
        .af = 1
    }>;
    st7735s_blk::init();
    st7735s_cs::init();
    st7735s_dc::init();
    st7735s_rst::init();
    st7735s_sck::init();
    st7735s_sda::init();

    using st7735s_spi = spi1<spi_init_cfg{
        .phase = false,
        .polarity = false,
        .clk_div = 16,
        .direction = spi_init_cfg::_direction::half_duplex_out
    }>;
    st7735s_spi::init();
    static constexpr auto cfg = [] {
        st7735s_cfg cfg(128, 160);
        cfg.x_mirror();
        cfg.xy_exchange();
        return cfg;
    }();
    using st7735s_adapter = st7735s_graphics2d_adapter<st7735s_spi, st7735s_cs, st7735s_dc, st7735s_sda, st7735s_sck, st7735s_rst, st7735s_blk, cfg>;
    graphics2d<st7735s_adapter> g2d;
    auto roboto_24px = find_font("Font_Roboto_24px");
    auto roboto_12px = find_font("Font_Roboto_12px");
    if (roboto_24px.success() && roboto_12px.success()) {
        for (u32 y = 0; y < st7735s_adapter::context::Height; ++y) {
            for (u32 x = 0; x < st7735s_adapter::context::Width; ++x) {
                g2d.draw_pixel(x, y, color_format_rgb565(255, 255, 255));
            }
        }
        timer0::init();
        auto draw_fps = [&] {

        };
        while (true) {
            g2d.draw_string(10, 26, roboto_24px, micronix::utf32_string_literal(U"micronix"));
            g2d.draw_string(10, 40, roboto_12px, micronix::utf32_string_literal(U"test ascii 1234"));
            g2d.present();
            timer0::alarm<0>({ 100 }, draw_fps);
        }
    }
}
