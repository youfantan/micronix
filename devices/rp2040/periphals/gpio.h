#pragma once

#include <limits>

#include "../../../include/peripherals/gpio.h"
#include "../register_spec.h"

template<u32 _OFF, typename _CTRL, typename _STATUS, typename _PAD, typename _OUT, typename _OUT_SET,
    typename _OUT_CLR, typename _OUT_XOR, typename _IN, typename _OE_SET, typename _OE_CLR, typename _OE, const auto& _RESET, const auto& _RESET_DONE>
struct gpio_reg {
    constexpr static u32 OFF = _OFF;
    using CTRL = _CTRL;
    using STATUS = _STATUS;
    using PAD = _PAD;
    using OUT = _OUT;
    using OUT_SET = _OUT_SET;
    using OUT_CLR = _OUT_CLR;
    using OUT_XOR = _OUT_XOR;
    using IN = _IN;
    using OE = _OE;
    using OE_SET = _OE_SET;
    using OE_CLR = _OE_CLR;

    constexpr static auto& RESET = _RESET;
    constexpr static auto& RESET_DONE = _RESET_DONE;
};

template<typename _REG, micronix::peripherals::gpio_init_cfg _CFG>
struct gpio {
    constexpr static u32 OFF = _REG::OFF;
    using CTRL = typename _REG::CTRL;
    using STATUS = typename _REG::STATUS;
    using PAD = typename _REG::PAD;
    using OUT = typename _REG::OUT;
    using OUT_SET = typename _REG::OUT_SET;
    using OUT_CLR = typename _REG::OUT_CLR;
    using OUT_XOR = typename _REG::OUT_XOR;
    using IN = typename _REG::IN;
    using OE_SET = typename _REG::OE_SET;
    using OE_CLR = typename _REG::OE_CLR;
    constexpr static auto& RESET = _REG::RESET;
    constexpr static auto& RESET_DONE = _REG::RESET_DONE;
    constexpr static micronix::peripherals::gpio_init_cfg CFG = _CFG;

    using mode = micronix::peripherals::gpio_init_cfg::_type;
    using pupd = micronix::peripherals::gpio_init_cfg::_pupd;

    constexpr static void init() {
        static_assert(CFG.af <= 0xF);
        // These reset lines are shared by every GPIO in bank 0.
        RESET = false;
        RESETS::RESET::PADS_BANK0 = false;
        while (!RESET_DONE || !RESETS::RESET_DONE::PADS_BANK0) {}
        if constexpr (CFG.type == mode::input) {
            PAD::OD = true;
            PAD::IE = true;
            PAD::SCHMITT = true;
            if constexpr (CFG.pupd == pupd::pullup) {
                PAD::PDE = false;
                PAD::PUE = true;
            } else if (CFG.pupd == pupd::pulldown) {
                PAD::PUE = false;
                PAD::PDE = true;
            } else {
                PAD::PUE = false;
                PAD::PDE = false;
            }
            if (CFG.direct) {
                CTRL::FUNCSEL = 0x05;
            } else {
                CTRL::FUNCSEL = CFG.af;
            }
        } else if (CFG.type == mode::output_od) {
            OUT_CLR::Write(1u << OFF);
            PAD::IE = false;
            PAD::OD = false;
            PAD::SLEWFAST = true;
            PAD::PUE = false;
            PAD::PDE = false;
            if constexpr (CFG.direct) {
                CTRL::FUNCSEL = 0x05;
                OE_SET::Write(1u << OFF);
            } else {
                CTRL::FUNCSEL = CFG.af;
            }
        } else if (CFG.type == mode::output_pp) {
            OUT_CLR::Write(1u << OFF);
            PAD::IE = false;
            PAD::OD = false;
            PAD::SLEWFAST = true;
            if constexpr (CFG.direct) {
                CTRL::FUNCSEL = 0x05;
                OE_SET::Write(1u << OFF);
            } else {
                CTRL::FUNCSEL = CFG.af;
            }
        } else if (CFG.type == mode::analog) {

        }
    }

    constexpr static void set() {
        static_assert(CFG.type == mode::output_od || CFG.type == mode::output_pp, "only output-type gpio could call set()");
        if constexpr (CFG.type == mode::output_pp) {
            OUT_SET::Write(1 << OFF);
        } else {
            OE_CLR::Write(1 << OFF);
            PAD::OD = true;
            PAD::IE = true;
        }
    }

    constexpr static void reset() {
        static_assert(CFG.type == mode::output_od || CFG.type == mode::output_pp, "only output-type gpio could call reset()");
        if constexpr (CFG.type == mode::output_pp) {
            OUT_CLR::Write(1 << OFF);
        } else {
            OE_SET::Write(1 << OFF);
            PAD::IE = false;
            PAD::OD = false;
        }
    }

    constexpr static void toggle() {
        static_assert(CFG.type == mode::output_pp, "only output-pp-type gpio could call toggle()");
        OUT_XOR::Write(1 << OFF);
    }

    constexpr static bool output() {
        static_assert(CFG.type == mode::output_od || CFG.type == mode::output_pp, "only output-type gpio could call output()");
        if constexpr (CFG.type == mode::output_od && CFG.direct) {
            using OE = typename _REG::OE;
            return (OE::Read() & (1u << OFF)) == 0;
        } else {
            return (OUT::Read() & (1u << OFF)) != 0;
        }
    }

    constexpr static bool input() {
        static_assert(CFG.type == mode::input, "only input-type gpio could call input()");
        return (IN::Read() & (1 << OFF)) >> OFF;
    }

    constexpr static bool is_null = OFF >= 0x1E;
};

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio0 = gpio<gpio_reg<0, IO_BANK0::GPIO0_CTRL, IO_BANK0::GPIO0_STATUS, PADS_BANK0::GPIO0,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio1 = gpio<gpio_reg<1, IO_BANK0::GPIO1_CTRL, IO_BANK0::GPIO1_STATUS, PADS_BANK0::GPIO1,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio2 = gpio<gpio_reg<2, IO_BANK0::GPIO2_CTRL, IO_BANK0::GPIO2_STATUS, PADS_BANK0::GPIO2,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio3 = gpio<gpio_reg<3, IO_BANK0::GPIO3_CTRL, IO_BANK0::GPIO3_STATUS, PADS_BANK0::GPIO3,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio4 = gpio<gpio_reg<4, IO_BANK0::GPIO4_CTRL, IO_BANK0::GPIO4_STATUS, PADS_BANK0::GPIO4,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio5 = gpio<gpio_reg<5, IO_BANK0::GPIO5_CTRL, IO_BANK0::GPIO5_STATUS, PADS_BANK0::GPIO5,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio6 = gpio<gpio_reg<6, IO_BANK0::GPIO6_CTRL, IO_BANK0::GPIO6_STATUS, PADS_BANK0::GPIO6,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio7 = gpio<gpio_reg<7, IO_BANK0::GPIO7_CTRL, IO_BANK0::GPIO7_STATUS, PADS_BANK0::GPIO7,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio8 = gpio<gpio_reg<8, IO_BANK0::GPIO8_CTRL, IO_BANK0::GPIO8_STATUS, PADS_BANK0::GPIO8,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio9 = gpio<gpio_reg<9, IO_BANK0::GPIO9_CTRL, IO_BANK0::GPIO9_STATUS, PADS_BANK0::GPIO9,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio10 = gpio<gpio_reg<10, IO_BANK0::GPIO10_CTRL, IO_BANK0::GPIO10_STATUS, PADS_BANK0::GPIO10,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio11 = gpio<gpio_reg<11, IO_BANK0::GPIO11_CTRL, IO_BANK0::GPIO11_STATUS, PADS_BANK0::GPIO11,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio12 = gpio<gpio_reg<12, IO_BANK0::GPIO12_CTRL, IO_BANK0::GPIO12_STATUS, PADS_BANK0::GPIO12,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio13 = gpio<gpio_reg<13, IO_BANK0::GPIO13_CTRL, IO_BANK0::GPIO13_STATUS, PADS_BANK0::GPIO13,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio14 = gpio<gpio_reg<14, IO_BANK0::GPIO14_CTRL, IO_BANK0::GPIO14_STATUS, PADS_BANK0::GPIO14,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio15 = gpio<gpio_reg<15, IO_BANK0::GPIO15_CTRL, IO_BANK0::GPIO15_STATUS, PADS_BANK0::GPIO15,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio16 = gpio<gpio_reg<16, IO_BANK0::GPIO16_CTRL, IO_BANK0::GPIO16_STATUS, PADS_BANK0::GPIO16,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio17 = gpio<gpio_reg<17, IO_BANK0::GPIO17_CTRL, IO_BANK0::GPIO17_STATUS, PADS_BANK0::GPIO17,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio18 = gpio<gpio_reg<18, IO_BANK0::GPIO18_CTRL, IO_BANK0::GPIO18_STATUS, PADS_BANK0::GPIO18,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio19 = gpio<gpio_reg<19, IO_BANK0::GPIO19_CTRL, IO_BANK0::GPIO19_STATUS, PADS_BANK0::GPIO19,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio20 = gpio<gpio_reg<20, IO_BANK0::GPIO20_CTRL, IO_BANK0::GPIO20_STATUS, PADS_BANK0::GPIO20,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio21 = gpio<gpio_reg<21, IO_BANK0::GPIO21_CTRL, IO_BANK0::GPIO21_STATUS, PADS_BANK0::GPIO21,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio22 = gpio<gpio_reg<22, IO_BANK0::GPIO22_CTRL, IO_BANK0::GPIO22_STATUS, PADS_BANK0::GPIO22,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio23 = gpio<gpio_reg<23, IO_BANK0::GPIO23_CTRL, IO_BANK0::GPIO23_STATUS, PADS_BANK0::GPIO23,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio24 = gpio<gpio_reg<24, IO_BANK0::GPIO24_CTRL, IO_BANK0::GPIO24_STATUS, PADS_BANK0::GPIO24,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio25 = gpio<gpio_reg<25, IO_BANK0::GPIO25_CTRL, IO_BANK0::GPIO25_STATUS, PADS_BANK0::GPIO25,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio26 = gpio<gpio_reg<26, IO_BANK0::GPIO26_CTRL, IO_BANK0::GPIO26_STATUS, PADS_BANK0::GPIO26,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio27 = gpio<gpio_reg<27, IO_BANK0::GPIO27_CTRL, IO_BANK0::GPIO27_STATUS, PADS_BANK0::GPIO27,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio28 = gpio<gpio_reg<28, IO_BANK0::GPIO28_CTRL, IO_BANK0::GPIO28_STATUS, PADS_BANK0::GPIO28,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;

template<micronix::peripherals::gpio_init_cfg cfg>
using gpio29 = gpio<gpio_reg<29, IO_BANK0::GPIO29_CTRL, IO_BANK0::GPIO29_STATUS, PADS_BANK0::GPIO29,
    SIO::GPIO_OUT, SIO::GPIO_OUT_SET, SIO::GPIO_OUT_CLR, SIO::GPIO_OUT_XOR, SIO::GPIO_IN,
    SIO::GPIO_OE_SET, SIO::GPIO_OE_CLR, SIO::GPIO_OE, RESETS::RESET::IO_BANK0, RESETS::RESET_DONE::IO_BANK0>, cfg>;
