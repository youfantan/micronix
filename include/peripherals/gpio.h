#pragma once

#include "../base.h"
#include <concepts>

namespace micronix::peripherals
{
    struct gpio_init_cfg {
        enum class io {
            input_floating,
            input_pullup,
            input_pulldown,
            output_pushpull,
            output_od,
            input_af,
            output_pushpull_af,
            output_od_af,
            analog
        } function;
    };

    template<typename gpio>
    concept is_gpio = requires(const gpio_init_cfg& cfg) {
        gpio::init(cfg);
        gpio::set();
        gpio::reset();
        gpio::output(true);
        { gpio::input() } -> std::same_as<bool>;
        gpio::destory();

        { gpio::null } -> std::same_as<const gpio&>;
        { gpio::is_null } -> std::same_as<const bool&>;
    };

    template<typename gpio>
    concept allow_null_gpio = requires
    {
        requires is_gpio<gpio>;
    };

    template<typename gpio>
    concept allow_unnull_gpio = requires
    {
        requires is_gpio<gpio>;
        requires !gpio::is_null;
    };
}