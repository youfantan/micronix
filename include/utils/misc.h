#pragma once

#include <base.h>

template<typename T,u32 N>
u32 count_of(T(&arr)[N]) {
    return N;
}