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

typedef void* handle;

// exported functions

void slab_initialize(slab_profile* profiles, u32 size);
u8* slab_alloc(u32 size);
void slab_free(u8* ptr);

void sched_initialize();
handle sched_create_process();
void sched_destroy_process(handle proc_handle);

void exception_initialize();
void exception_throw();
}