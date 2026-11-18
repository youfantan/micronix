#pragma once

#include <ratio>
#include <type_traits>

#include "../../../include/peripherals/spi.h"
#include "../register_spec.h"

template<typename _SPI, const auto& _RESET, const auto& _RESET_DONE>
struct spi_reg {
    using SSPCR0 = typename _SPI::SSPCR0;
    using SSPCR1 = typename _SPI::SSPCR1;
    using SSPCPSR = typename _SPI::SSPCPSR;
    using SSPDR = typename _SPI::SSPDR;
    using SSPSR = typename _SPI::SSPSR;

    constexpr static auto& RESET = _RESET;
    constexpr static auto& RESET_DONE = _RESET_DONE;
};

template<typename _REG, micronix::peripherals::spi_init_cfg _CFG>
struct spi {
    using REG = _REG;
    using SSPCR0 = typename REG::SSPCR0;
    using SSPCR1 = typename REG::SSPCR1;
    using SSPCPSR = typename REG::SSPCPSR;
    using SSPDR = typename REG::SSPDR;
    using SSPSR = typename REG::SSPSR;
    using CLK_PERI_CTRL = CLOCKS::CLK_PERI_CTRL;
    constexpr static auto& RESET = _REG::RESET;
    constexpr static auto& RESET_DONE = _REG::RESET_DONE;

    constexpr static micronix::peripherals::spi_init_cfg CFG = _CFG;
    constexpr static u32 FRAME_BITS = 8;
    constexpr static u32 FIFO_DEPTH = 8;

    using direction = micronix::peripherals::spi_init_cfg::_direction;

    constexpr static void init() {
        CLK_PERI_CTRL::ENABLE = true;

        RESET = true;
        RESET = false;
        while (!RESET_DONE) {}

        SSPCPSR::CPSDVSR = CFG.clk_div;
        SSPCR0::DSS = FRAME_BITS - 1;
        SSPCR0::SPH = CFG.phase;
        SSPCR0::SPO = CFG.polarity;
        SSPCR1::SSE = true;
    }

    constexpr static bool rx_available() {
        static_assert(CFG.direction == direction::half_duplex_in || CFG.direction == direction::full_duplex, "only rx-only or full duplex spi could call rx_available()");
        return SSPSR::RNE;
    }

    constexpr static bool tx_available() {
        static_assert(CFG.direction == direction::half_duplex_out || CFG.direction == direction::full_duplex, "only tx-only or full duplex spi could call tx_available()");
        return SSPSR::TNF;
    }

    constexpr static u8 read() {
        static_assert(CFG.direction == direction::half_duplex_in || CFG.direction == direction::full_duplex, "only rx-only or full duplex spi could call read()");
        return static_cast<u8>(SSPDR::Read());
    }

    constexpr static void write(u8 byte) {
        static_assert(CFG.direction == direction::half_duplex_out || CFG.direction == direction::full_duplex, "only tx-only or full duplex spi could call write()");
        SSPDR::Write(byte);
    }

    constexpr static void batched_read_blocking(u8* dest, u32 len) {
        static_assert(CFG.direction == direction::half_duplex_in || CFG.direction == direction::full_duplex, "only rx-only or full duplex spi could call batched_read_blocking()");
        for (u32 i = 0; i < len; ++i) {
            while (!rx_available()) {}
            dest[i] = read();
        }
    }

    constexpr static void batched_write_blocking(const u8* src, u32 len) {
        static_assert(CFG.direction == direction::half_duplex_out || CFG.direction == direction::full_duplex, "only rx-only or full duplex spi could call batched_write_blocking()");
        for (u32 i = 0; i < len; ++i) {
            while (!tx_available()) {}
            write(src[i]);
        }
    }
};


template<micronix::peripherals::spi_init_cfg cfg>
using spi0 = spi<spi_reg<SPI0, RESETS::RESET::SPI0, RESETS::RESET_DONE::SPI0>, cfg>;

template<micronix::peripherals::spi_init_cfg cfg>
using spi1 = spi<spi_reg<SPI1, RESETS::RESET::SPI1, RESETS::RESET_DONE::SPI1>, cfg>;
