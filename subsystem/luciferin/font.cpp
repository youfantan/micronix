#include <luciferin/font.h>
#include <utils/algorithms.h>

using namespace micronix::luciferin;

glyph_meta* micronix::luciferin::find_glyph(void* base, u32 face_base, u32 unicode) {
    auto* header = reinterpret_cast<font_face_meta*>(static_cast<u8*>(base) + face_base);
    auto* indices = reinterpret_cast<glyph_index*>(reinterpret_cast<u8*>(header) + sizeof(font_face_meta));
    auto found = binary_search(indices, header->glyphs, { unicode });
    if (found) return reinterpret_cast<glyph_meta*>(static_cast<u8*>(base) + found->offset);
    return nullptr;
}
