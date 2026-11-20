#include <base.h>
#include <rp2040/periphals/gpio.h>
#include <rp2040/periphals/spi.h>
#include "../modules/st7735s.h"
void app_main() {
    using namespace micronix::peripherals;
    using namespace micronix::modules;

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
        cfg.xy_exchange();
        return cfg;
    }();
    using st7735s = st7735s<st7735s_spi, st7735s_cs, st7735s_dc, st7735s_sda, st7735s_sck, st7735s_rst, st7735s_blk, cfg>;
    

}