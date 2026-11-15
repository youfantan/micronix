#pragma once

#include "../base.h"
#include "../../include/utils/string.h"

#include <concepts>

namespace micronix::peripherals
{
    struct spi_config {
        u32 device_id;
        u32 bitrate;
        enum class spi_direction {
            half_duplex_in,
            half_duplex_out,
            full_duplex
        } direction;
    };

    template<typename spi>
    concept is_spi = requires(const spi_config& cfg, u8 byte, const utf8_string& string, const u8* data, u32 len, u8* src)
    {
        spi::init(cfg);
        { spi::write_byte(byte) } -> std::same_as<bool>;
        { spi::read_byte() } -> std::same_as<u8>;
        { spi::batch_write(string) } -> std::same_as<bool>;
        { spi::batch_read() } -> std::same_as<utf8_string>;
        { spi::batch_write(data, len) } -> std::same_as<bool>;
        spi::batch_read(src, len);
        spi::destroy();
    };
}
