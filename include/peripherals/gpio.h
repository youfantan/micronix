#pragma once

#include "../base.h"
#include <concepts>

namespace micronix::peripherals
{
    struct gpio_init_cfg {
        enum class _type {
            input,
            output_od,
            output_pp,
            analog,
        } type;
        enum class _pupd {
            pullup,
            pulldown,
            floating,
        } pupd;
        bool direct;
        u8 af;
    };

    template<typename gpio>
    concept is_gpio = requires {
        requires std::same_as<const gpio_init_cfg, decltype(gpio::CFG)>;
        gpio::init();
        { gpio::is_null } -> std::same_as<const bool&>;
    } && (
        gpio::CFG.type == gpio_init_cfg::_type::analog ||
        (gpio::CFG.type == gpio_init_cfg::_type::input && requires {
            { gpio::input() } -> std::same_as<bool>;
        }) ||
        ((gpio::CFG.type == gpio_init_cfg::_type::output_od || gpio::CFG.type == gpio_init_cfg::_type::output_pp) &&
            requires {
                gpio::set();
                gpio::reset();
                { gpio::output() } -> std::same_as<bool>;
            } &&
            (gpio::CFG.type == gpio_init_cfg::_type::output_od || requires {
                gpio::toggle();
            }))
    );

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
