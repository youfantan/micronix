#pragma once

#define RAM_BASE_ADDRESS 0x20000000
#define RAM_SIZE 0x2000

#include <stdint.h>

#include "base.h"

#define __I  volatile const
#define __O  volatile
#define __IO volatile

#define __ASM            __asm
#define __INLINE         inline
#define __STATIC_INLINE  static inline
#define __WEAK           __attribute__((weak))

__STATIC_INLINE void __NOP(void)        { __ASM volatile ("nop"); }
__STATIC_INLINE void __WFI(void)        { __ASM volatile ("wfi"); }
__STATIC_INLINE void __enable_irq(void) { __ASM volatile ("cpsie i"); }
__STATIC_INLINE void __disable_irq(void){ __ASM volatile ("cpsid i"); }

struct RegisterFieldDescriptor {
    u8 off;
    u8 len;
};

template<uint32_t ADDR, RegisterFieldDescriptor RFD>
struct RegisterField {
    const RegisterField& operator=(u32 value) const {
        *reinterpret_cast<volatile uint32_t*>(ADDR) = (*reinterpret_cast<volatile uint32_t*>(ADDR) & ~mask) | ((value << RFD.off) & mask);
        return *this;
    }

    operator uint32_t() const {
        return (*reinterpret_cast<volatile uint32_t*>(ADDR) & ~mask) >> RFD.off;
    }
private:
    constexpr static uint32_t mask = (0xFFFFFFFF >> (32 - RFD.len)) << RFD.off;
};

#define DECL_REGISTER(Base) \
template<RegisterFieldDescriptor RFD> \
using RegisterField = RegisterField<Base, RFD>

#include "register_spec.h"