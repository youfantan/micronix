#pragma once

#include <base.h>

static inline void __NOP(void)        { __asm volatile ("nop"); }
static inline void __WFI(void)        { __asm volatile ("wfi"); }
static inline void __enable_irq(void) { __asm volatile ("cpsie i"); }
static inline void __disable_irq(void){ __asm volatile ("cpsid i"); }

enum class oscillator_type {
    external_crystal_oscillator,
    internal_rc_oscillator
};

struct clock_config {
    oscillator_type osc_type;
    u32 base_freq;
    u32 mp_factor;
    u32 pll_p;
    u32 pll_q;
};