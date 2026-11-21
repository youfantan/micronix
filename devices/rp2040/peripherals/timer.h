#pragma once

#include "../../../include/kernel/interrupts.h"
#include "../../../include/peripherals/timer.h"
#include "../register_spec.h"
#include <memory>


namespace micronix::devices::rp2040
{

    constexpr static peripherals::timer_init_cfg timer_cfg {
        .tick_precision = tick_frequency_hz,
        .max_alarm_count = 4
    };

    template<peripherals::timer_init_cfg _CFG>
    struct timer {
        constexpr static peripherals::timer_init_cfg CFG = _CFG;
        static_assert(CFG.tick_precision == tick_frequency_hz);
        static_assert(CFG.max_alarm_count == 4);

        struct _alarm {
            using invoke_fn = void (*)(void*);
            invoke_fn volatile invoke = nullptr;
            void* context = nullptr;
        };
        constexpr static auto no_exec_alarm() {
            return reinterpret_cast<_alarm::invoke_fn>(0xFFFFFFFFu);
        }

        static void init() {
            irq_critical_guard lock;
            static bool deasserted = false;
            if (!deasserted) {
                RESETS::RESET::TIMER = false;
                while (!RESETS::RESET_DONE::TIMER) {}
            }
            reset();
            resume();
            TIMER::INTE::Write(alarm_mask);
            PPB::NVIC_ISER::Write(alarm_mask);
        }

        static peripherals::tick32 tick_count32() {
            return { TIMER::TIMERAWL::Read() };
        }

        static void tick_count64(peripherals::tick64& t64) {
            do {
                t64.high = TIMER::TIMERAWH::Read();
                t64.low = TIMER::TIMERAWL::Read();
            } while (t64.high != TIMER::TIMERAWH::Read());
        }

        static void pause() {
            TIMER::PAUSE::PAUSE_ = 1;
        }

        static void resume() {
            TIMER::PAUSE::PAUSE_ = 0;
        }

        static void reset() {
            irq_critical_guard guard;
            TIMER::TIMELW::Write(0);
            TIMER::TIMEHW::Write(0);
        }

        template<u32 I, typename F>
        requires (I < CFG.max_alarm_count && std::invocable<F&>)
        static bool alarm(peripherals::tick32 ticks, F& callback) {
            irq_critical_guard guard;
            auto* address = static_cast<const volatile void*>(&callback);
            auto& ticket = alarms[I];
            if (ticket.invoke != nullptr) return false;
            ticket.invoke = [](void* ptr) {
                (*static_cast<F*>(ptr))();
            };
            ticket.context = const_cast<void*>(address);
            auto start = TIMER::TIMELR::Read();
            u32 deadline = start + ticks.low;
            if constexpr (I == 0) {
                TIMER::ALARM0::Write(deadline);
            } else if (I == 1) {
                TIMER::ALARM1::Write(deadline);
            } else if (I == 2) {
                TIMER::ALARM2::Write(deadline);
            } else if (I == 3) {
                TIMER::ALARM3::Write(deadline);
            }
            u32 now = TIMER::TIMELR::Read();
            if (now - start >= ticks.low) {
                constexpr u32 mask = 1u << I;
                TIMER::ARMED::Write(mask);
                TIMER::INTF::Write(TIMER::INTF::Read() | mask);
            }
            return true;
        }

        template<u32 I> requires (I < CFG.max_alarm_count)
        static bool alarm(peripherals::tick32 ticks) {
            irq_critical_guard guard;
            auto& ticket = alarms[I];
            if (ticket.invoke != nullptr) return false;
            ticket.invoke = no_exec_alarm();
            u32 start = TIMER::TIMELR::Read();
            u32 deadline = start + ticks.low;
            if constexpr (I == 0) {
                TIMER::ALARM0::Write(deadline);
            } else if (I == 1) {
                TIMER::ALARM1::Write(deadline);
            } else if (I == 2) {
                TIMER::ALARM2::Write(deadline);
            } else if (I == 3) {
                TIMER::ALARM3::Write(deadline);
            }
            u32 now = TIMER::TIMELR::Read();
            if (now - start >= ticks.low) {
                constexpr u32 mask = 1u << I;
                TIMER::ARMED::Write(mask);
                TIMER::INTF::Write(TIMER::INTF::Read() | mask);
            }
            return true;
        }

        template<u32 I> requires (I < CFG.max_alarm_count)
        static void cancel_alarm() {
            irq_critical_guard guard;
            constexpr static u32 mask = 1 << I;
            TIMER::ARMED::Write(mask);
            TIMER::INTR::Write(mask);
            TIMER::INTF::Write(TIMER::INTF::Read() & ~mask);
            PPB::NVIC_ICPR::Write(mask);
            alarms[I].invoke = nullptr;
            alarms[I].context = nullptr;
        }

        template<u32 I> requires (I < CFG.max_alarm_count)
        static void wait_alarm() {
            if (alarms[I].invoke == nullptr) return;
            while (alarms[I].invoke != nullptr) {}
        }

        static void destroy() {
            irq_critical_guard guard;
            PPB::NVIC_ICER::Write(alarm_mask);
            TIMER::INTE::Write(0);
            TIMER::ARMED::Write(alarm_mask);
            TIMER::INTR::Write(alarm_mask);
            TIMER::INTF::Write(0);
            PPB::NVIC_ICPR::Write(alarm_mask);
            for (auto& alarm : alarms) {
                alarm = {};
            }
            TIMER::PAUSE::PAUSE_ = 1;
        }

        static constexpr u32 tick_to_us(peripherals::tick32 ticks) {
            return static_cast<u32>(static_cast<u64>(ticks.low) * 1'000'000 / CFG.tick_precision);
        }

        template<u32 I> requires (I < CFG.max_alarm_count)
        static void alarm_intr() {
            typename _alarm::invoke_fn invoke;
            void* context;
            auto& alarm = alarms[I];
            {
                irq_critical_guard guard;
                constexpr u32 mask = 1u << I;
                if (!(TIMER::INTS::Read() & mask)) return;
                u32 f = TIMER::INTF::Read();
                if (f & mask) TIMER::INTF::Write(f & ~mask);
                TIMER::INTR::Write(mask);
                invoke = alarm.invoke;
                context = alarm.context;
                alarm.invoke = nullptr;
                alarm.context = nullptr;
            }
            if (invoke && invoke != no_exec_alarm()) {
                invoke(context);
            }
        }

    private:
        inline static _alarm alarms[CFG.max_alarm_count] {};
        static constexpr u32 alarm_mask = (1u << CFG.max_alarm_count) - 1;
    };

    using timer0 = timer<timer_cfg>;
}
