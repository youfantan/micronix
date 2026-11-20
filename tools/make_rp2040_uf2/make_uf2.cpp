#include "../common/cpp/buffer.h"
#include <iostream>
#include <fstream>
#include <vector>

#include "cpp/exception.h"

struct Elf32_Ehdr {
    uint8_t  e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
};

struct Elf32_Shdr {
    uint32_t sh_name;
    uint32_t sh_type;
    uint32_t sh_flags;
    uint32_t sh_addr;
    uint32_t sh_offset;
    uint32_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint32_t sh_addralign;
    uint32_t sh_entsize;
};

struct Elf32_Phdr {
    uint32_t p_type;
    uint32_t p_offset;
    uint32_t p_vaddr;
    uint32_t p_paddr;
    uint32_t p_filesz;
    uint32_t p_memsz;
    uint32_t p_flags;
    uint32_t p_align;
};

struct UF2_Block {
    uint32_t magic_start0 { 0x0A324655 };
    uint32_t magic_start1 { 0x9E5D5157 };
    uint32_t flags { 0x00002000 };
    uint32_t target_addr {};
    uint32_t payload_size {256};
    uint32_t block_no {};
    uint32_t num_blocks {};
    uint32_t family_id { 0xE48BFF56 };
    uint8_t data[476] {};
    uint32_t magic_end { 0x0AB16F30 };
};

void make_rp2040_crc32(const uint8_t* stage2_text, uint8_t* crc) {
    uint32_t crc32 = 0xFFFFFFFFu;

    for (size_t i = 0; i < 252; ++i) {
        crc32 ^= static_cast<uint32_t>(static_cast<uint8_t>(stage2_text[i])) << 24;
        for (int bit = 0; bit < 8; ++bit) {
            if (crc32 & 0x80000000u) {
                crc32 = (crc32 << 1) ^ 0x04C11DB7u;
            } else {
                crc32 <<= 1;
            }
        }
    }

    crc[0] = static_cast<uint8_t>(crc32 & 0xFFu);
    crc[1] = static_cast<uint8_t>((crc32 >> 8) & 0xFFu);
    crc[2] = static_cast<uint8_t>((crc32 >> 16) & 0xFFu);
    crc[3] = static_cast<uint8_t>((crc32 >> 24) & 0xFFu);
}

int main(int argc, char** argv) {
    RTCheck(argc == 3, "Usage: micronix-make-rp2040-uf2 /path/to/input/elf /path/to/output/uf2");
    std::string input_elf_path(argv[1]);
    std::string output_uf2_path(argv[2]);
    std::ifstream input_elf(input_elf_path, std::ios::in | std::ios::binary);
    RTCheck(input_elf.good(), "Cannot open input elf file {}", input_elf_path);
    std::ofstream output_uf2(output_uf2_path, std::ios::out | std::ios::binary);
    RTCheck(output_uf2.good(), "Cannot open output uf2 file {}", output_uf2_path);
    uint64_t len;
    input_elf.seekg(0, std::ios::end);
    len = input_elf.tellg();
    input_elf.seekg(0, std::ios::beg);
    byte_buffer buffer;
    buffer.reserve(len);
    input_elf.read(reinterpret_cast<char*>(&buffer[0]), len);
    input_elf.close();
    std::ofstream output_elf(input_elf_path, std::ios::out | std::ios::binary);
    const auto* ehdr = reinterpret_cast<const Elf32_Ehdr*>(&buffer[0]);
    RTCheck(std::memcmp(ehdr->e_ident, "\x7f" "ELF", 4) == 0, "Unrecognized ELF magic");
    RTCheck(ehdr->e_ident[4] == 1, "Requires 32-bit ELF");
    RTCheck(ehdr->e_ident[5] == 1, "Requires little-endian ELF");
    RTCheck(ehdr->e_shentsize == sizeof(Elf32_Shdr), "Unexpected section header size");
    RTCheck(ehdr->e_phentsize == sizeof(Elf32_Phdr), "Unexpected program header size");
    RTCheck(ehdr->e_shstrndx < ehdr->e_shnum, "Invalid shstrndx");
    const auto* shdrs = reinterpret_cast<const Elf32_Shdr*>(&buffer[ehdr->e_shoff]);
    const auto* shstrtab_hdr = &shdrs[ehdr->e_shstrndx];
    const auto* shstrtab_off = reinterpret_cast<const char*>(&buffer[shstrtab_hdr->sh_offset]);
    int64_t stage2_off = -1;
    for (uint64_t i = 0; i < ehdr->e_shnum; ++i) {
        const auto* shdr = &shdrs[i];
        std::string section_name = &shstrtab_off[shdr->sh_name];
        if (section_name == ".stage2") {
            RTCheck(shdr->sh_size == 256, ".stage section must be 256 bytes");
            stage2_off = shdr->sh_offset;
        }
    }
    RTCheck(stage2_off != -1, "Cannot found .stage2 section");
    make_rp2040_crc32(&buffer[stage2_off], &buffer[stage2_off + 252]);
    output_elf.write(reinterpret_cast<const char*>(&buffer[0]), len);
    const auto* phdrs = reinterpret_cast<const Elf32_Phdr*>(&buffer[ehdr->e_phoff]);
    std::vector<const Elf32_Phdr*> selected_phdrs;
    uint64_t aligned_begin { std::numeric_limits<uint64_t>::max() }, aligned_end {};
    for (uint64_t i = 0; i < ehdr->e_phnum; ++i) {
        const auto* phdr = &phdrs[i];
        if (phdr->p_type == 0x01 && phdr->p_filesz > 0) {
            selected_phdrs.push_back(phdr);
            uint64_t p_aligned_begin = phdr->p_paddr & ~0xFFFull;
            uint64_t p_aligned_end = (phdr->p_paddr + phdr->p_filesz + 4095) & ~0xFFFull;
            if (p_aligned_begin < aligned_begin) aligned_begin = p_aligned_begin;
            if (p_aligned_end > aligned_end) aligned_end = p_aligned_end;
        }
    }
    RTCheck(!selected_phdrs.empty(), "No loadable segments found in the ELF");
    byte_buffer uf2_buffer;
    std::vector<bool> marked_uf2_blocks((aligned_end - aligned_begin) / 256);
    uf2_buffer.reserve(aligned_end - aligned_begin);
    for (auto phdr : selected_phdrs) {
        uint64_t offset = phdr->p_paddr - aligned_begin;
        memcpy(&uf2_buffer[offset], &buffer[phdr->p_offset], phdr->p_filesz);
        uint64_t beg_blk_idx = phdr->p_paddr / 256;
        uint64_t end_blk_idx = (phdr->p_paddr + phdr->p_filesz + 255) / 256;
        uint64_t sub = aligned_begin / 256;
        for (auto i = beg_blk_idx; i < end_blk_idx; ++i) {
            marked_uf2_blocks[i - sub] = true;
        }
    }
    for (uint64_t i = 0; i < marked_uf2_blocks.size() / 16; ++i) {
        bool padding = false;
        for (uint64_t j = i * 16; j < (i + 1) * 16; ++j) {
            if (marked_uf2_blocks[j]) padding = true;
        }
        if (padding) {
            for (uint64_t j = i * 16; j < (i + 1) * 16; ++j) {
                marked_uf2_blocks[j] = true;
            }
        }
    }
    std::vector<UF2_Block> uf2_blocks;
    for (uint64_t i = 0; i < marked_uf2_blocks.size(); ++i) {
        if (marked_uf2_blocks[i]) {
            uf2_blocks.emplace_back();
            uf2_blocks.back().target_addr = aligned_begin + i * 256;
            memcpy(uf2_blocks.back().data, &uf2_buffer[i * 256], 256);
        }
    }
    for (uint64_t i = 0; i < uf2_blocks.size(); ++i) {
        uf2_blocks[i].block_no = i;
        uf2_blocks[i].num_blocks = uf2_blocks.size();
        output_uf2.write(reinterpret_cast<const char*>(&uf2_blocks[i]), sizeof(uf2_blocks[i]));
    }
}
