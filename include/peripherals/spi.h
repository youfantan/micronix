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

    template <template <typename, spi_init_cfg> typename spi, typename reg, spi_init_cfg cfg>
    concept is_spi = requires(u8* dest, const u8* src, u32 len, u8 byte)
    {
        spi<reg, cfg>::init();
        requires((cfg.direction == spi_init_cfg::_direction::half_duplex_in || cfg.direction ==
                spi_init_cfg::_direction::full_duplex) &&
            requires
            {
                { spi<reg, cfg>::rx_available() } -> std::same_as<bool>;
                { spi<reg, cfg>::read() } -> std::same_as<u8>;
                spi<reg, cfg>::batched_read_blocking(dest, len);
            });
        requires(
            (cfg.direction == spi_init_cfg::_direction::half_duplex_out || cfg.direction ==
                spi_init_cfg::_direction::full_duplex) &&
            requires
            {
                { spi<reg, cfg>::tx_available() } -> std::same_as<bool>;
                spi<reg, cfg>::write(byte);
                spi<reg, cfg>::batched_write_blocking(src, len);
            });
    };
}
