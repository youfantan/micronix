#pragma once

#include "../../include/base.h"

namespace micronix::devices::rp2040 {
    inline constexpr u32 tick_frequency_hz = 1'000'000;
}

inline constexpr u64 operator""_mhz(u64 freq) {
    return freq * 1000 * 1000;
}

inline constexpr u64 operator""_khz(u64 freq) {
    return freq * 1000;
}

struct clock_config {
    u32 target_frequency_hz;
    u32 osc_frequency_hz;
    u32 sys_fb_div;
    u32 usb_fb_div;
    u32 sys_div1;
    u32 sys_div2;
    u32 usb_div1;
    u32 usb_div2;
};
