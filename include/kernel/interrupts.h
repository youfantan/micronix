#pragma once

#include "../base.h"

namespace micronix
{
    struct irq_critical_guard {
        u32 primask;
        irq_critical_guard() { asm volatile("mrs %0, primask\n cpsid i" : "=r"(primask) :: "memory"); }
        ~irq_critical_guard() { asm volatile("msr primask, %0" :: "r"(primask) : "memory"); }
    };
}