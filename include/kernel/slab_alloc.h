#pragma once

#include <base.h>

namespace micronix::kernel
{
    struct slab_profile {
        u32 block_size;
        u32 slots;
    };

    void slab_initialize();
    void* slab_alloc(u32 size);
    void slab_free(void* ptr);

    void sched_initialize();
}