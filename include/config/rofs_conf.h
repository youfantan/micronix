#pragma once
#include <base.h>

extern "C" uint32_t _flash_rofs_image_begin[];
extern "C" uint32_t _flash_rofs_image_end[];

constexpr static uint32_t ROFS_KeySize = 16;
constexpr static uint32_t ROFS_Entries = 2;
constexpr static uint32_t ROFS_ImageSize = 14336;
constexpr static uint32_t* ROFS_ImageBase = _flash_rofs_image_begin;
constexpr static uint32_t* ROFS_ImageEnd = _flash_rofs_image_end;
constexpr static uint32_t ROFS_entry_Font_Roboto_12px = 4;
constexpr static uint32_t ROFS_entry_Font_Roboto_24px = 28;
