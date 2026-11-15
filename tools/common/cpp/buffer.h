#pragma once

#include <cstdint>
#include <vector>
#include <cstring>

template<typename T>
class array_view {
    uint8_t** base_;
    uint64_t offset_;
    uint64_t size_;
public:
    array_view(uint8_t** base, uint64_t offset, uint64_t size) : base_(base), offset_(offset), size_(size) {

    }
    array_view(array_view&) = delete;
    array_view(array_view&&) = delete;

    T& operator[](uint64_t i) {
        return reinterpret_cast<T*>(*base_ + offset_)[i];
    }

    const T& operator[](uint64_t i) const {
        return reinterpret_cast<T*>(*base_ + offset_)[i];
    }

    ~array_view() = default;
};

class byte_buffer {
    uint8_t* data_;
    uint8_t** base_;
    uint64_t index_;
    uint64_t capacity_;

    constexpr static uint64_t InitialCapacity = 32 * 1024;
    constexpr static uint64_t MinExpandCapacity = 1024;
public:
    byte_buffer() : data_(new uint8_t[InitialCapacity]), base_(new uint8_t*(data_)) ,index_(0) ,capacity_(InitialCapacity) {
        memset(data_, 0, InitialCapacity);
    }

    byte_buffer(byte_buffer& other) : data_(new uint8_t[other.capacity_]), base_(new uint8_t*(data_)), index_(0), capacity_(other.capacity_) {
        *base_ = data_;
        memcpy(data_, other.data_, capacity_);
    }

    byte_buffer(byte_buffer&& other) noexcept : data_(other.data_), base_(other.base_), index_(other.index_), capacity_(other.capacity_) {
        other.base_ = nullptr;
        other.data_ = nullptr;
    }

    template<typename T>
        void append(const std::vector<T>& buffer) {
        auto require_capacity = index_ + buffer.size() * sizeof(T);
        if (require_capacity > capacity_) expand(require_capacity);
        if (!buffer.empty()) {
            memcpy(data_ + index_, buffer.data(), buffer.size() * sizeof(T));
            index_ += buffer.size() * sizeof(T);
        }
    }

    template<typename T>
    void append(const T& data) {
        auto require_capacity = index_ + sizeof(T);
        if (require_capacity > capacity_) expand(require_capacity);
        memcpy(data_ + index_, &data, sizeof(T));
        index_ += sizeof(T);
    }

    template<typename T>
    void append(const T* data, uint64_t len) {
        auto require_capacity = index_ + sizeof(T) * len;
        if (require_capacity > capacity_) expand(require_capacity);
        memcpy(data_ + index_, data, sizeof(T) * len);
        index_ += sizeof(T) * len;
    }

    void forward(uint64_t size) {
        auto require_capacity = index_ + size;
        if (require_capacity > capacity_) expand(require_capacity);
        index_ += size;
    }

    void reserve(uint64_t index) {
        auto require_capacity = index;
        if (require_capacity > capacity_) expand(require_capacity);
    }

    template<typename T>
    array_view<T> get_array_view(uint64_t offset, uint64_t size) {
        return { base_, offset, size };
    }

    uint8_t& operator[](uint64_t i) {
        return data_[i];
    }

    void expand(uint64_t new_capacity) {
        if (new_capacity - capacity_ <= MinExpandCapacity) {
            new_capacity = capacity_ + MinExpandCapacity;
        }
        auto* new_buffer = new uint8_t[new_capacity];
        memset(new_buffer, 0, new_capacity);
        memcpy(new_buffer, data_, capacity_);
        delete[] data_;
        capacity_ = new_capacity;
        data_ = new_buffer;
        *base_ = data_;
    }

    uint64_t index() {
        return index_;
    }

    uint64_t capacity() const {
        return capacity_;
    }

    ~byte_buffer() {
        if (data_ != nullptr) {
            delete base_;
            delete[] data_;
        }
    }
};