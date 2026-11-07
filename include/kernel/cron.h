#pragma once

#include <base.h>

namespace micronix::kernel
{
    struct tick{
        u32 tick_high;
        u32 tick_low;
    };

    void timer_initialize();
    void timer_sleep(u32 us);

    void cron_init();
    tick cron_ticks();
}