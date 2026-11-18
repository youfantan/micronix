#pragma once

extern "C" {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;
typedef void* handle;

static_assert(sizeof(i8) == 1);
static_assert(static_cast<int>(static_cast<i8>(-1)) == -1);

void clock_init();
void kernel_entry();
void app_main();

void memzero(void* ptr, u32 size);
void memcopy(void* dest, const void* src, u32 size);
}

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

inline void WriteRegister(u32 addr, u32 value) {
    *(volatile u32*)(addr) = value;
}

inline u32 ReadRegister(u32 addr) {
    return *(volatile u32*)(addr);
}

template <u32 ADDR, u8 OFFSET, u8 LENGTH>
inline constexpr void WriteRegisterField(u32 value) {
    constexpr u32 mask = (0xFFFFFFFF >> (32 - LENGTH)) << OFFSET;
    *reinterpret_cast<volatile u32*>(ADDR) = (*reinterpret_cast<volatile u32*>(ADDR) & ~mask) | ((value << OFFSET) &
        mask);
}

template <u32 ADDR, u8 OFFSET, u8 LENGTH>
inline constexpr u32 ReadRegisterField() {
    constexpr u32 mask = (0xFFFFFFFF >> (32 - LENGTH)) << OFFSET;
    return (*reinterpret_cast<volatile u32*>(ADDR) & mask) >> OFFSET;
}

template <u32 ADDR>
inline constexpr void WriteRegister(u32 value) {
    *reinterpret_cast<volatile u32*>(ADDR) = value;
}

template <u32 ADDR>
inline constexpr u32 ReadRegister() {
    return *reinterpret_cast<volatile u32*>(ADDR);
}


template <u32 _ADDR, RegisterFieldDescriptor _RFD>
struct RegisterField {
    constexpr static u32 ADDR = _ADDR;
    constexpr static RegisterFieldDescriptor RFD = _RFD;

    const RegisterField& operator=(u32 value) const {
        Write(value);
        return *this;
    }

    operator u32() const {
        return Read();
    }

    void Write(u32 value) const {
        *reinterpret_cast<volatile u32*>(ADDR) = (*reinterpret_cast<volatile u32*>(ADDR) & ~mask) | ((value << RFD.off) & mask);
    }

    u32 Read() const {
        return (*reinterpret_cast<volatile u32*>(ADDR) & mask) >> RFD.off;
    }

private:
    constexpr static u32 mask = (0xFFFFFFFF >> (32 - RFD.len)) << RFD.off;
};

#define DECL_REGISTER(Base) \
    template<RegisterFieldDescriptor RFD> \
    using RegisterField = RegisterField<Base, RFD>; \
    constexpr static u32 Read() { \
        return ReadRegister<Base>(); \
    } \
    constexpr static void Write(u32 value) { \
        WriteRegister<Base>(value); \
    }

