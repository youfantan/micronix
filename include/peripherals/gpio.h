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

    template<template<typename, gpio_init_cfg> typename gpio, typename reg, gpio_init_cfg cfg>
    concept is_gpio = requires {
        gpio<reg, cfg>::init();
        { gpio<reg, cfg>::is_null } -> std::same_as<const bool&>;
    } && (
        cfg.type == gpio_init_cfg::_type::analog ||
        (cfg.type == gpio_init_cfg::_type::input && requires {
            { gpio<reg, cfg>::input() } -> std::same_as<bool>;
        }) ||
        ((cfg.type == gpio_init_cfg::_type::output_od || cfg.type == gpio_init_cfg::_type::output_pp) &&
            requires {
                gpio<reg, cfg>::set();
                gpio<reg, cfg>::reset();
                { gpio<reg, cfg>::output() } -> std::same_as<bool>;
            } &&
            (cfg.type == gpio_init_cfg::_type::output_od || requires {
                gpio<reg, cfg>::toggle();
            }))
    );

    template<template<typename, gpio_init_cfg> typename gpio, typename reg, gpio_init_cfg cfg>
    concept allow_null_gpio = requires
    {
        requires is_gpio<gpio, reg, cfg>;
    };

    template<template<typename, gpio_init_cfg> typename gpio, typename reg, gpio_init_cfg cfg>
    concept allow_unnull_gpio = requires
    {
        requires is_gpio<gpio, reg, cfg>;
        requires !gpio<reg, cfg>::is_null;
    };
}
