#pragma once

extern "C" {
// global defination

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

// exported types

typedef struct {
    u32 block_size;
    u32 slots;
} slab_profile;

typedef struct {
    u32 fcpu;
} timer_profile;

typedef struct {
    u32 tick_high;
    u32 tick_low;
} tick;

typedef void* handle;

// exported functions

void slab_initialize(const slab_profile* profiles, u32 size);
u8* slab_alloc(u32 size);
void slab_free(u8* ptr);

void sched_initialize();

/*
 * Create process by a function pointer and process profile.
 * Sched will create a process context associated with the function pointer. process will be scheduled in many time slices until sched_destroy_process() is called.
 */
handle sched_create_process();

/*
 * Destroy process by handle.
 * A process should call this function at the end of the control flow. Sched will recycle all resources associated with this process.
 */
void sched_destroy_process(handle proc_handle);

/*
 * Disable processes schedule and switch.
 * Used in precision sequences control flow like software-implemented high speed bus.
 * When called, sched stop working, util sched_recovery_switching() is called; meanwhile SysTick context is also paused and stored, precision timer could only be used in this status.
 */
void sched_block_switching();

/*
 * Recovery process schedule and switch.
 * When called, sched continue working; SysTick will be reconfigured using stored context.
 */
void sched_recovery_switching();

void exception_initialize();
void exception_throw();

void timer_initialize(timer_profile* profile);
void timer_sleep(tick ticks);
tick timer_now();
u32 timer_ticks_to_ms(tick* t);
u32 timer_ticks_to_us(tick* t);
tick timer_ms_to_ticks(u32 ms);
tick timer_us_to_ticks(u32 us);

}