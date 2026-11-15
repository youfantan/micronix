#pragma once

#include "../base.h"
#include "algorithms.h"

#include <new>
#include <type_traits>

struct failed_t {};
constexpr static failed_t failed;
template<typename T>
class result {
    bool success_;
    alignas(T) u8 storage_[sizeof(T)];

    T* data() {
        return std::launder(reinterpret_cast<T*>(storage_));
    }

    const T* data() const {
        return std::launder(reinterpret_cast<const T*>(storage_));
    }
public:
    result(failed_t) : success_(false), storage_{} {}

    template<typename U = T>
    requires (!std::is_same_v<std::remove_cvref_t<U>, bool> &&!std::is_same_v<std::remove_cvref_t<U>, result> && !std::is_same_v<std::remove_cvref_t<U>, failed_t> && std::is_constructible_v<T, U&&>)
    explicit(!std::is_convertible_v<U&&, T>)
    result(U&& value) noexcept : success_(true) {
        ::new (static_cast<void*>(storage_)) T(static_cast<U&&>(value));
    }

    result(const result& r) requires (std::is_copy_constructible_v<T>) : success_(r.success_) {
        if (success_) {
            ::new (static_cast<void*>(storage_)) T(*r.data());
        }
    }

    result(result&& r) noexcept(std::is_nothrow_move_constructible_v<T>)
        requires (std::is_move_constructible_v<T>) : success_(r.success_) {
        if (success_) {
            ::new (static_cast<void*>(storage_)) T(::move(*r.data()));
        }
    }

    result& operator=(const result&) = delete;
    result& operator=(result&&) = delete;

    bool success() const {
        return success_;
    }

    T& get() {
        return *data();
    }

    const T& get() const {
        return *data();
    }

    operator T&() {
        return *data();
    }

    operator const T&() const {
        return *data();
    }

    T* operator->() {
        return data();
    }

    const T* operator->() const {
        return data();
    }

    operator bool() const {
        return success_;
    }

    ~result() {
        if (success_) {
            data()->~T();
        }
    }
};

template<typename T>
class result<T*> {
    bool success_;
    T* ptr_;
public:
    result(failed_t) : success_(false), ptr_(nullptr) {}
    result(T* value) : success_(true), ptr_(value) {}
    result(const result& other) = default;
    result(result&& other) = default;

    bool success() const {
        return success_;
    }

    T* get() {
        return ptr_;
    }

    const T* get() const {
        return ptr_;
    }

    operator T*() {
        return ptr_;
    }

    operator const T*() const {
        return ptr_;
    }

    T* operator->() {
        return ptr_;
    }

    const T* operator->() const {
        return ptr_;
    }

    operator bool() const {
        return success_;
    }
};

template<typename T>
class result<const T*> {
    bool success_;
    const T* ptr_;
public:
    result(failed_t) : success_(false), ptr_(nullptr) {}
    result(const T* value) : success_(true), ptr_(value) {}
    result(const result& other) = default;
    result(result&& other) = default;

    bool success() const {
        return success_;
    }

    const T* get() const {
        return ptr_;
    }

    operator const T*() const {
        return ptr_;
    }

    const T* operator->() const {
        return ptr_;
    }

    operator bool() const {
        return success_;
    }
};
