#pragma once

extern "C" {

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;
typedef void* handle;

void clock_initialize();
void kernel_entry();

}

namespace micronix
{
    enum access_type : u8 {
        RW = 0,
        R,
        W,
        R_WOnce,
        WOnce,
    };

    typedef struct {
        u8 off;
        u8 len;
        u8 access;
    } RegisterFieldDescriptor;


    inline void WriteRegisterField(u32 addr, u8 offset, u8 length, u32 value) {
        const u32 mask = (0xFFFFFFFF >> (32 - length)) << offset;
        *(volatile u32*)(addr) = (*(volatile u32*)(addr) & ~mask) | ((value << offset) & mask);
    }

    inline u32 ReadRegisterField(u32 addr, u8 offset, u8 length) {
        const u32 mask = (0xFFFFFFFF >> (32 - length)) << offset;
        return (*reinterpret_cast<volatile u32*>(addr) & mask) >> offset;
    }

    template<u32 ADDR, u8 OFFSET, u8 LENGTH>
    inline void WriteRegisterField(u32 value) {
        constexpr static u32 mask = (0xFFFFFFFF >> (32 - LENGTH)) << OFFSET;
        *reinterpret_cast<volatile u32*>(ADDR) = (*reinterpret_cast<volatile u32*>(ADDR) & ~mask) | ((value << OFFSET) & mask);
    }

    template<u32 ADDR, u8 OFFSET, u8 LENGTH>
    inline u32 ReadRegisterField() {
        constexpr static u32 mask = (0xFFFFFFFF >> (32 - LENGTH)) << OFFSET;
        return (*reinterpret_cast<volatile u32*>(ADDR) & mask) >> OFFSET;
    }


    template<u32 _ADDR, RegisterFieldDescriptor _RFD>
    struct RegisterField {
        constexpr static u32 ADDR = _ADDR;
        constexpr static RegisterFieldDescriptor RFD = _RFD;

        const RegisterField& operator=(u32 value) const {
            Set(value);
            return *this;
        }

        operator u32() const {
            return Get();
        }

        void Set(u32 value) const {
            *reinterpret_cast<volatile u32*>(ADDR) = (*reinterpret_cast<volatile u32*>(ADDR) & ~mask) | ((value << RFD.off) & mask);
        }

        u32 Get() const {
            return (*reinterpret_cast<volatile u32*>(ADDR) & mask) >> RFD.off;
        }
    private:
        constexpr static u32 mask = (0xFFFFFFFF >> (32 - RFD.len)) << RFD.off;
    };

    #define DECL_REGISTER(Base) \
    template<RegisterFieldDescriptor RFD> \
    using RegisterField = RegisterField<Base, RFD>


}