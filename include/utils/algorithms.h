#pragma once

#include "../base.h"
#include "algorithms.h"

#include <concepts>
#include <cstddef>
#include <type_traits>

template<typename T>
const T* binary_search(const T* array, u32 size, const T& value) {
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

template<typename T, typename... Ts>
constexpr T max_of(const T& v, const Ts&... vs) {
    auto max = v;
    auto update = [&](const auto& x) {
        max = x > max ? x : max;
    };
    (update(vs), ...);
    return max;
}

template<typename T, typename R, bool _BeginClosed, bool _EndClosed>
constexpr bool in_range(const T& value, const R& begin, const R& end) {
    bool b {}, e {};
    if constexpr (_BeginClosed) {
        b = value >= begin;
    } else {
        b = value > begin;
    }
    if constexpr (_EndClosed) {
        e = value <= end;
    } else {
        e = value < end;
    }
    return b && e;
}

template<typename T, typename R>
constexpr bool in_range_co(const T& value, const R& begin, const R& end) {
    return in_range<T, R, true, false>(value, begin, end);
}

template<typename T, typename R>
constexpr bool in_range_cc(const T& value, const R& begin, const R& end) {
    return in_range<T, R, true, true>(value, begin, end);
}

template<typename T, typename R>
constexpr auto& in_range_oc(const T& value, const R& begin, const R& end) {
    return in_range<T, R, false, true>(value, begin, end);
}
template<typename T, typename R>
constexpr auto& in_range_oo(const T& value, const R& begin, const R& end) {
    return in_range<T, R, false, false>(value, begin, end);
}

template<typename T,u32 N>
constexpr u32 count_of(T(&arr)[N]) {
    return N;
}

template<typename T>
struct remove_reference {
    using type = T;
};

template<typename T>
struct remove_reference<T&> {
    using type = T;
};

template<typename T>
struct remove_reference<T&&> {
    using type = T;
};

template<typename T>
constexpr typename remove_reference<T>::type&& move(T&& t) noexcept {
    return static_cast<typename remove_reference<T>::type&&>(t);
}

template<typename T>
concept movable = requires(typename remove_reference<T>::type&& right)
{
    remove_reference<T>::type(right);
};

template<auto Value, typename Rp>
struct match_rule {
    using value_type = decltype(Value);
    constexpr static value_type value = Value;

    Rp rp;
    constexpr void operator()() const {
        rp();
    }
};

template<auto Value, typename Rp>
constexpr auto make_match_rule(Rp rp) {
    return match_rule<Value, Rp>{::move(rp)};
}

template<auto E_Max, typename E, typename... Rules>
requires std::same_as<decltype(E_Max), E> && (std::same_as<typename Rules::value_type, E> && ...)
constexpr void match(const E& e, const Rules&... rules) {
    static_assert(((Rules::value <= E_Max) && ...), "match rule value exceeds E_Max");
    static_assert([] {
        constexpr E values[] = {Rules::value..., E_Max};
        for (std::size_t i = 0; i < sizeof...(Rules); ++i) {
            for (std::size_t j = i + 1; j < sizeof...(Rules); ++j) {
                if (values[i] == values[j]) return false;
            }
        }
        return true;
    }(), "match rules must have unique values");

    if (e > E_Max) return;
    (void)((e == Rules::value ? (static_cast<void>(rules.rp()), true) : false) || ...);
}
