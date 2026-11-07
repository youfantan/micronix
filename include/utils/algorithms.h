#pragma once

#include <base.h>

template<typename T>
static T* binary_search(T* array, u32 size, const T& value) {
    u32 begin = 0;
    u32 end = size;
    while (begin < end) {
        u32 index = begin + (end - begin) / 2;
        if (array[index] == value) return &array[index];
        if (array[index] > value) {
            end = index;
        } else {
            begin = index + 1;
        }
    }
    return nullptr;
}