#pragma once

#include <device.h>
#include <kernel/slab_alloc.h>

constexpr static clock_config clk_cfg {
    .target_frequency_hz = 125_mhz,
    .osc_frequency_hz = 12_mhz,
    .sys_fb_div = 125,
    .usb_fb_div = 96,
    .sys_div1 = 6,
    .sys_div2 = 2,
    .usb_div1 = 6,
    .usb_div2 = 4
};

constexpr micronix::kernel::slab_profile slab_prof[3] = {
    {
        .block_size = 32,
        .slots = 64
    },
    {
        .block_size = 64,
        .slots = 16
    },
    {
        .block_size = 256,
        .slots = 4
    }
};
