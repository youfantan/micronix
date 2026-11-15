#pragma once

#include "../../include/base.h"

inline constexpr u64 operator""_mhz(u64 freq) {
    return freq * 1000 * 1000;
}

inline constexpr u64 operator""_khz(u64 freq) {
    return freq * 1000;
}

struct clock_config {
    u32 target_frequency_hz;
    u32 osc_frequency_hz;
    u32 fb_div;
    u32 post_div1;
    u32 post_div2;
};

void clock_init();