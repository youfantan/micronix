#pragma once
#include <base.h>

extern "C" u32 _flash_rofs_imgbase[];

constexpr static u32 ROFS_KeySize = 16;
constexpr static u32 ROFS_Entries = 2;
constexpr static u32 ROFS_ImageSize = 14336;
constexpr static u32* ROFS_ImageBase = _flash_rofs_imgbase;
constexpr static u32 ROFS_entry_Font_Roboto_12px = 4;
constexpr static u32 ROFS_entry_Font_Roboto_24px = 28;
