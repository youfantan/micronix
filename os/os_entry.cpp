#include <base.h>
#include <sys_conf.h>
#include <device_spec.h>
#include <cortexm0_spec.h>
#include <utils.h>

extern int main();

volatile u32 HighTicks = 0;
volatile u32 LowTicks = 0;

extern "C" {

void system_init() {
    ClockInitialize<clk_cfg>();
}

int kernel_init() {
    slab_initialize();
    main();
    return 0;
}

void timer_initialize() {
}

void SysTick_Handler() {
    LowTicks += 1;
    if (LowTicks == 0xFFFFFFFFul) {
        HighTicks += 1;
        LowTicks = 0;
    }
}

void* memset(void* dst, int val, u32 len) {
    u8* d = static_cast<u8*>(dst);
    for (u32 i = 0; i < len; ++i) {
        d[i] = static_cast<u8>(val);
    }
    return dst;
}

void* memcpy(void* dst, const void* src, u32 len) {
    const u8* s = static_cast<const u8*>(src);
    u8* d = static_cast<u8*>(dst);
    for (u32 i = 0; i < len; ++i) {
        d[i] = s[i];
    }
    return dst;
}

void* memmove(void* dst, const void* src, u32 len) {
    const u8* s = static_cast<const u8*>(src);
    u8* d = static_cast<u8*>(dst);
    if (d < s) {
        for (u32 i = 0; i < len; ++i) {
            d[i] = s[i];
        }
    } else if (d > s) {
        for (u32 i = len; i > 0; --i) {
            d[i - 1] = s[i - 1];
        }
    }
    return dst;
}

}