#pragma once

#include "../base.h"
#include "../utils/containers.h"

namespace micronix::peripherals
{
    using tick32 = struct _tick32 {
        u32 low;
    };

    using tick64 = struct _tick64 {
        u32 low;
        u32 high;
    };

    struct timer_init_cfg {
        u32 tick_precision;
        u32 max_alarm_count;
    };

    template<typename timer>
    concept is_timer = requires (tick64& t64, tick32 t32)
    {
        { timer::CFG } -> std::same_as<const timer_init_cfg&>;
        typename timer::ticket;
        timer::init();
        { timer::tick_count32() } -> std::same_as<tick32>;
        timer::tick_count64(t64);
        timer::pause();
        timer::resume();
        timer::reset();
        { timer::template alarm<timer::CFG.max_alarm_count - 1>(t32, [t32] { }) } -> std::same_as<bool>;
        { timer::template alarm<timer::CFG.max_alarm_count - 1>(t32) } -> std::same_as<bool>;
        timer::template cancel_alarm<timer::CFG.max_alarm_count - 1>();
        timer::template wait_alarm<timer::CFG.max_alarm_count - 1>();
        timer::destroy();
        { timer::tick_to_us(t32) } -> std::same_as<u32>;
    };
}

