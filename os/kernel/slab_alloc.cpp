#include <base.h>
#include <kernel/slab_alloc.h>
#include <conf.h>
#include <utils/misc.h>

using namespace micronix::kernel;

constexpr u32 SlabHeapSize() {
    u32 total = 0;
    for (const slab_profile& p : slab_prof) {
        total += p.block_size * p.slots;
    }
    return total;
}

constexpr u32 SlabTableSize() {
    u32 total = 0;
    for (const slab_profile& p : slab_prof) {
        total += 32;
    }
    return total;
}

alignas(8) u8 SlabTable[SlabTableSize()];
alignas(8) u8 SlabHeap[SlabHeapSize()];

void micronix::kernel::slab_initialize() {
    memzero(SlabTable, SlabTableSize());
    memzero(SlabHeap, SlabHeapSize());
    u8* mptr = SlabHeap;
    for (u32 i = 0; i < count_of(slab_prof); ++i) {
        u32* ptr = reinterpret_cast<u32*>(&SlabTable[i * 32]);
        *ptr = reinterpret_cast<u32>(mptr);
        mptr += slab_prof[i].block_size * slab_prof[i].slots;
    }
}

void* micronix::kernel::slab_alloc(u32 size) {
    u32 region = count_of(slab_prof);
    for (u32 i = 0; i < count_of(slab_prof); ++i) {
        if (size <= slab_prof[i].block_size) {
            region = i;
            break;
        }
    }
    if (region == count_of(slab_prof)) { // memory to be allocated is too large
        return nullptr;
    }
    u8* base = reinterpret_cast<u8*>(reinterpret_cast<u32*>(&SlabTable[region * 32])[0]);
    u8* bitmap = &SlabTable[region * 32 + 4];
    for (u32 idx = 0; idx < slab_prof[region].slots; ++idx) {
        if (!((bitmap[idx >> 3] >> (idx & 7)) & 1)) {
            bitmap[idx >> 3] |= 1u << (idx & 7);
            return base + idx * slab_prof[region].block_size;
        }
    }
    return nullptr; // no free block
}

void micronix::kernel::slab_free(void* ptr) {
    if (ptr == nullptr) {
        return;
    }
    for (u32 region = 0; region < count_of(slab_prof); ++region) {
        u8* base = reinterpret_cast<u8*>(reinterpret_cast<u32*>(&SlabTable[region * 32])[0]);
        const u32 block = slab_prof[region].block_size;
        const u32 span = block * slab_prof[region].slots;
        if (ptr < base || ptr >= base + span) {
            continue;
        }
        const u32 off = static_cast<u32>(static_cast<u8*>(ptr) - base);
        if (off % block != 0) {
            return;
        }
        const u32 idx = off / block;
        if (idx < slab_prof[region].slots) {
            (&SlabTable[region * 32 + 4])[idx >> 3] &= ~(1u << (idx & 7));
        }
        return;
    }
}