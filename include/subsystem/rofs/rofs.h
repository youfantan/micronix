#pragma once

#include "../../base.h"
#include "../../config/rofs_conf.h"
#include "../../utils/containers.h"
#include "../../utils/algorithms.h"
#include "../../utils/string.h"

namespace micronix::rofs
{
    struct rofs_header {
        u32 version;
    };

    struct rofs_entry {
        char key[ROFS_KeySize];
        u32 size;
        u32 offset;

        bool operator==(const rofs_entry& other) const {
            for (u32 i = 0; i < ROFS_KeySize; ++i) {
                if (key[i] != other.key[i]) return false;
            }
            return true;
        }

        bool operator>(const rofs_entry& other) const {
            for (u32 i = 0; i < ROFS_KeySize; ++i) {
                if (key[i] != other.key[i]) return static_cast<u8>(key[i]) > static_cast<u8>(other.key[i]);
            }
            return false;
        }

    };

    static_assert(ROFS_KeySize > 0 && ROFS_KeySize % 4 == 0);

    inline const void* rofs_find_direct(u32 direct) {
        const auto* r = reinterpret_cast<const rofs_entry*>(reinterpret_cast<const u8*>(ROFS_ImageBase) + direct);
        const u8* data = reinterpret_cast<const u8*>(ROFS_ImageBase) + r->offset;
        return data;
    }

    inline result<const void*> rofs_find_by_key(const u8* key, u32 size) {
        if (size > ROFS_KeySize) return failed;
        const void* base = ROFS_ImageBase;
        const auto* header = static_cast<const rofs_header*>(base);
        const auto* entry = reinterpret_cast<const rofs_entry*>(header + 1);
        rofs_entry search {};
        memcopy(&search.key, key, size);
        const rofs_entry* r = binary_search(entry, ROFS_Entries, search);
        if (r == nullptr) return failed;
        return reinterpret_cast<const u8*>(ROFS_ImageBase) + r->offset;
    }

    template<typename T>
    const T* rofs_find_direct(u32 direct) {
        const auto* r = reinterpret_cast<const rofs_entry*>(reinterpret_cast<const u8*>(ROFS_ImageBase) + direct);
        const u8* data = reinterpret_cast<const u8*>(ROFS_ImageBase) + r->offset;
        return reinterpret_cast<const T*>(data);
    }

    template<typename T>
    result<const T*> rofs_find_by_string(const utf8_string_literal& literal) {
        if (literal.len() > ROFS_KeySize) return failed;
        const void* base = ROFS_ImageBase;
        const auto* header = static_cast<const rofs_header*>(base);
        const auto* entry = reinterpret_cast<const rofs_entry*>(header + 1);
        rofs_entry search {};
        memcopy(&search.key, literal.str(), literal.len());
        const rofs_entry* r = binary_search(entry, ROFS_Entries, search);
        if (r == nullptr) return failed;
        if (sizeof(T) > r->size) return failed;
        return reinterpret_cast<const T*>(reinterpret_cast<const u8*>(ROFS_ImageBase) + r->offset);
    }
}
