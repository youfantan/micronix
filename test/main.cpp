#include <base.h>
#include <rp2040/periphals/gpio.h>
#include <rp2040/periphals/spi.h>
void app_main() {
    constexpr static micronix::peripherals::gpio_init_cfg cfg {
        .type = micronix::peripherals::gpio_init_cfg::_type::output_pp,
        .direct = true,
        .af = 5
    };
    using reg = gpio_reg<0,
    IO_BANK0::GPIO0_CTRL,
    IO_BANK0::GPIO0_STATUS,
    PADS_BANK0::GPIO0,
    SIO::GPIO_OUT,
    SIO::GPIO_OUT_SET,
    SIO::GPIO_OUT_CLR,
    SIO::GPIO_OUT_XOR,
    SIO::GPIO_IN,
    SIO::GPIO_OE_SET,
    SIO::GPIO_OE_CLR
    >;
    gpio<reg, cfg> gp;
}