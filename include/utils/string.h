#pragma once

#include "../base.h"
#include "../kernel/slab_alloc.h"

namespace micronix
{
    template<typename T>
    u32 strlen(const T* str) {
        for (u32 i = 0; ; ++i) {
            if (str[i] == 0) return i;
        }
    }

    template<typename T>
    class string_literal {
        const T* data_;
        u32 len_;
    public:
        string_literal(const T* string) : data_(string), len_(strlen(string)) {}

        string_literal(string_literal& other) = default;
        string_literal(string_literal&& other) noexcept : data_(other.data_), len_(other.len_) {
            other.data_ = nullptr;
            other.len_ = 0;
        }

        string_literal& operator=(const string_literal& other) = default;
        string_literal& operator=(string_literal&& other) noexcept {
            data_ = other.data_;
            len_ = other.len_;
            other.data_ = nullptr;
            other.len_ = 0;
            return *this;
        }

        const T* str() const {
            return data_;
        }

        u32 len() const {
            return len_;
        }

        const T& operator[](u32 index) const {
            return data_[index];
        }
    };

    using utf8_string_literal = string_literal<char>;
    using utf16_string_literal = string_literal<char16_t>;
    using utf32_string_literal = string_literal<char32_t>;

    template<typename T>
    class string {
        T* data_;
        u32 len_;
    public:
        string(const T* str) : string(strlen(str)) {
            memcopy(data_, str, sizeof(T) * len_);
        }

        explicit string(u32 len) : data_(static_cast<T*>(micronix::kernel::slab_alloc(sizeof(T) * len))), len_(len) {
            if (!data_) len_ = 0;
            memzero(data_, sizeof(T) * len_);
        }

        string(const string& other) : string(other.len_) {
            memcopy(data_, other.data_, len_ * sizeof(T));
        }

        string(string&& other) noexcept : data_(other.data_), len_(other.len_) {
            other.data_ = nullptr;
            other.len_ = 0;
        }

        u32 len() const {
            return len_;
        }

        const T* str() const {
            return data_;
        }

        T& operator[](u32 index) {
            return data_[index];
        }

        const T& operator[](u32 index) const {
            return data_[index];
        }

        string& operator=(const string& other) {
            if (&other == this) return *this;
            T* data = static_cast<T*>(micronix::kernel::slab_alloc(sizeof(T) * other.len_));
            if (!data && other.len_) return *this;
            memcopy(data, other.data_, other.len_ * sizeof(T));
            micronix::kernel::slab_free(data_);
            data_ = data;
            len_ = other.len_;
            return *this;
        }

        string& operator=(string&& other) noexcept {
            if (&other == this) return *this;
            micronix::kernel::slab_free(data_);
            data_ = other.data_;
            len_ = other.len_;
            other.data_ = nullptr;
            other.len_ = 0;
            return *this;
        }

        ~string() {
            micronix::kernel::slab_free(data_);
        }
    };

    using utf8_string = string<char>;
    using utf16_string = string<char16_t>;
    using utf32_string = string<char32_t>;

    template<typename T>
    string<T> from_number(u64 n) {

    }

    template<typename T>
    string<T> from_number(float fp) {

    }
}