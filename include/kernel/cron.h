#pragma once

#include "../base.h"
#include "../../devices/cortexm0_spec.h"
#include "../include/config/kern_conf.h"

namespace micronix::kernel
{
    struct tick{
        u32 tick_high;
        u32 tick_low;
    };

    constexpr static u32 systick_k_us = clk_cfg.target_frequency_hz / 1000000;

    inline void timer_initialize() {
        SysTick::CSR::CLKSOURCE = 0x01; // Set clock reference to processor clock
    }
    inline void timer_sleep(u32 us) {
        SysTick::CVR::CURRENT = 0;
        SysTick::RVR::RELOAD = systick_k_us * us;
        SysTick::CSR::ENABLE = true;
        while (!SysTick::CSR::COUNTFLAG) {}
        SysTick::CSR::ENABLE = false;
    }

    void cron_init();
    tick cron_ticks();
}