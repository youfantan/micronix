#include <algorithm>
#include <format>
#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

#include <base.h>
#include <buffer.h>

#define ASSERT(cond, msg) if (!(cond)) { std::cout << "Fatal at expression '" << #cond << "': " << msg << std::endl; exit(EXIT_FAILURE); }

struct file {
    std::string path;
    std::vector<u8> alias;
    u32 align;
    u32 entry_offset;
    u32 image_offset;
    std::string content;

    file() : align(1), entry_offset(0), image_offset(0) {}
    file(file&) = delete;
    file(file&& other) noexcept : path(std::move(other.path)), alias(std::move(other.alias)), align(other.align), entry_offset(other.entry_offset), image_offset(other.image_offset), content(std::move(other.content)) {}
    file& operator=(file&) = delete;
    file& operator=(file&& other) noexcept {
        path = std::move(other.path);
        alias = std::move(other.alias);
        align = other.align;
        entry_offset = other.entry_offset;
        image_offset = other.image_offset;
        content = std::move(other.content);
        return *this;
    }
    ~file() = default;
};

struct configuration {
    u32 version;
    std::string output_path;
    u32 key_size;
    u32 page_size;
    std::vector<file> collect_files;

    configuration() : version(1), output_path("./rofs.image.bin"), key_size(0), page_size(0), collect_files() {

    }

    configuration(configuration&) = delete;
    configuration(configuration&& other) noexcept : version(other.version), output_path(std::move(other.output_path)), key_size(other.key_size), page_size(other.page_size), collect_files(std::move(other.collect_files)) {}
    ~configuration() = default;
};

std::vector<std::string> parse_line(const std::string& line) {
    std::stringstream ss(line);
    std::vector<std::string> result(1);
    while (ss >> result.back()) {
        result.emplace_back();
    }
    result.pop_back();
    return result;
}

u32 string_to_u32(const std::string& str) {
    return std::atoi(str.c_str());
}

configuration parse_config(const std::string& config_path) {
    std::ifstream cfg_in(config_path, std::ios::in | std::ios::binary);
    ASSERT(cfg_in.good(), "Image profile not found");
    std::string line;
    ASSERT(static_cast<bool>(std::getline(cfg_in, line)), "Cannot read image profile header");
    auto magic = parse_line(line);
    ASSERT(magic.size() == 2 && magic[0] == "micronix::rofs" && magic[1] == "v1", "first line must be micronix::rofs v1");
    configuration cfg {};
    cfg.version = 0x01;
    while (std::getline(cfg_in, line)) {
        auto splitted = parse_line(line);
        if (splitted.empty()) continue;
        if (splitted[0].starts_with('.')) {
            ASSERT(splitted.size() == 2, "Illegal image params size");
            if (splitted[0] == ".keysize") {
                cfg.key_size = string_to_u32(splitted[1]);
                ASSERT(cfg.key_size > 0 && cfg.key_size % 4 == 0, "Keysize must be multiple of 4");
            } else if (splitted[0] == ".pagesize") {
                cfg.page_size = string_to_u32(splitted[1]);
            } else if (splitted[0] == ".output") {
                cfg.output_path = splitted[1];
            } else {
                ASSERT(false, std::format("Illgal image param: {}", splitted[0]));
            }
        } else if (splitted[0] == "collect") {
            ASSERT(cfg.key_size != 0, "Keysize must be set before collect");
            ASSERT(!splitted.empty() && splitted.size() % 2 == 0 && splitted.size() >= 4 && splitted.size() <= 6, "Illegal collect params size");
            file f {};
            auto& path = splitted[1];
            std::ifstream fin(path, std::ios::in | std::ios::binary);
            ASSERT(fin.good(), std::format("Cannot open input file {}", path));
            f.path = path;
            fin.seekg(0, std::ios::end);
            auto len = fin.tellg();
            ASSERT(len >= 0 && len < std::numeric_limits<u32>::max(), std::format("Invalid or too large input file {}", path));
            fin.seekg(0, std::ios::beg);
            f.content.resize(len);
            if (len > 0) fin.read(f.content.data(), len);
            ASSERT(fin.good(), std::format("Cannot read input file {}", path));
            for (std::size_t i = 2; i < splitted.size(); i += 2) {
                auto& k = splitted[i];
                auto& v = splitted[i + 1];
                if (k == "align") {
                    f.align = string_to_u32(v);
                } else if (k == "alias") {
                    ASSERT(v.size() <= cfg.key_size, "alias of file is larger than keysize");
                    f.alias.resize(cfg.key_size);
                    memcpy(&f.alias[0], &v[0], v.size());
                } else {
                    ASSERT(false, std::format("Illegal collect param: {}", k));
                }
            }
            ASSERT(!f.alias.empty(), "Alias is required in collect");
            cfg.collect_files.push_back(std::move(f));
        } else {
            ASSERT(false, std::format("Unrecognized line begin: {}", splitted[0]));
        }
    }
    ASSERT(cfg.page_size > 0, "Pagesize is required");
    for (const auto& f : cfg.collect_files) {
        ASSERT(f.align > 0 && cfg.page_size % f.align == 0, "Align must be positive and divide pagesize");
    }
    std::cout << std::format(R"(micronix::rofs Image details
version {}
output path: {}
key size: {}
page size: {}
collect files: {}
)", cfg.version, cfg.output_path, cfg.key_size, cfg.page_size, cfg.collect_files.size()) << std::endl;
    return cfg;
}

byte_buffer collect_image(configuration& cfg) {
    byte_buffer image_buffer;
    image_buffer.append<u32>(0x01);
    auto& files = cfg.collect_files;
    std::ranges::sort(files.begin(), files.end(), [&](const file& a, const file& b) {
        for (u32 i = 0; i < cfg.key_size; ++i) {
            if (a.alias[i] == b.alias[i]) continue;
            return a.alias[i] < b.alias[i];
        }
        return false;
    });
    for (std::size_t i = 1; i < files.size(); ++i) {
        ASSERT(files[i - 1].alias != files[i].alias, "Repeated alias is illegal");
    }
    u64 entry_offset = image_buffer.index();
    u64 image_offset = image_buffer.index() + (cfg.key_size + sizeof(u32) * 2) * files.size();
    for (auto & f : files) {
        if (image_offset % f.align != 0) image_offset = ((image_offset + f.align - 1) / f.align) * f.align;
        ASSERT(image_offset + f.content.size() < std::numeric_limits<u32>::max(), "Image size is too large");
        image_buffer.append(f.alias);
        image_buffer.append(static_cast<u32>(f.content.size()));
        image_buffer.append(static_cast<u32>(image_offset));
        f.entry_offset = entry_offset;
        f.image_offset = image_offset;
        entry_offset += cfg.key_size + sizeof(u32) * 2;
        image_offset += f.content.size();
        std::string alias_str(cfg.key_size, 0);
        memcpy(&alias_str[0], &f.alias[0], f.alias.size());
        std::cout << std::format("Collected {}: alias '{}', align {}, offset {}", f.path, alias_str, f.align, f.image_offset) << std::endl;
    }
    for (auto & f : files) {
        image_buffer.reserve(f.image_offset + f.content.size());
        image_buffer.forward(f.image_offset - image_buffer.index());
        image_buffer.append(&f.content[0], f.content.size());
    }
    u32 reserved_for_align = image_buffer.index() % cfg.page_size == 0 ? 0 : (image_buffer.index() + cfg.page_size - 1) / cfg.page_size * cfg.page_size - image_buffer.index();
    image_buffer.forward(reserved_for_align);
    ASSERT(image_buffer.index() < std::numeric_limits<u32>::max(), "Image size is too large");
    return image_buffer;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: micronix-rofs-collect.exe image_profile" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    auto cfg = parse_config(argv[1]);
    auto image = collect_image(cfg);
    std::ofstream image_out(cfg.output_path, std::ios::out | std::ios::binary);
    ASSERT(image_out.good(), "Cannot open output image");
    image_out.write(reinterpret_cast<const char*>(&image[0]), image.index());
    std::ofstream header_out("./rofs_conf.h", std::ios::out | std::ios::binary);
    ASSERT(header_out.good(), "Cannot open output configuration");
    std::stringstream header;
    header << std::format(R"(#pragma once
#include <base.h>

extern "C" u32 _flash_rofs_imgbase[];

constexpr static u32 ROFS_KeySize = {};
constexpr static u32 ROFS_Entries = {};
constexpr static u32 ROFS_ImageSize = {};
constexpr static u32* ROFS_ImageBase = _flash_rofs_imgbase;
)", cfg.key_size, cfg.collect_files.size(), image.index());
    for (auto& f : cfg.collect_files) {
        std::string alias(cfg.key_size, 0);
        memcpy(&alias[0], &f.alias[0], f.alias.size());
        header << std::format("constexpr static u32 ROFS_entry_{} = {};", alias, f.entry_offset ) << std::endl;
    }
    header_out << header.str();
    return 0;
}
