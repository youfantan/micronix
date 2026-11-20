#pragma once
#include <format>
#include <string>
#include <iostream>
#include <source_location>

#define RTCheck(expr, fmt, ...) _rt_check((expr), #expr, std::source_location::current(), fmt, __VA_ARGS__)

template<typename... Args>
void _rt_check(bool s, const std::string& expr, const std::source_location& loc, const std::string& fmt_str, Args&&... args) {
    if (!s) {
        std::string msg = std::vformat(fmt_str, std::make_format_args(std::forward<Args>(args)...));
        std::cout << std::format("Error occurs in expression: '{}' ({}:{}): \n{}", expr, loc.file_name(), loc.column(), msg) << std::endl;
        exit(EXIT_FAILURE);
    }
}
