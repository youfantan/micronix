#pragma once

#include "../base.h"
#include "../../include/utils/string.h"

#include <concepts>

namespace micronix::peripherals
{
    struct spi_init_cfg {
        bool phase;
        bool polarity;
        u32 clk_div;

        enum class _direction {
            half_duplex_in,
            half_duplex_out,
            full_duplex
        } direction;
    };

    template<typename spi>
    concept is_spi = requires(u8* dest, const u8* src, u32 len, u8 byte)
    {
        requires std::same_as<const spi_init_cfg, decltype(spi::CFG)>;
        spi::init();
        requires
        ((spi::CFG.direction == spi_init_cfg::_direction::half_duplex_in || spi::CFG.direction ==
                spi_init_cfg::_direction::full_duplex) &&
            requires
            {
                { spi::rx_available() } -> std::same_as<bool>;
                { spi::read() } -> std::same_as<u8>;
                spi::batched_read_blocking(dest, len);
            }) ||
        ((spi::CFG.direction == spi_init_cfg::_direction::half_duplex_out || spi::CFG.direction ==
                spi_init_cfg::_direction::full_duplex) &&
            requires
        {
            { spi::tx_available() } -> std::same_as<bool>;
            spi::write(byte);
            spi::batched_write_blocking(src, len);
        });
    };
}
