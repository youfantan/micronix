cmake_minimum_required(VERSION 3.22)
project(micronix_font_sample LANGUAGES CXX)

if(NOT MSVC)
    message(FATAL_ERROR
        "tools/font_sample must be configured with the Microsoft Visual C++ compiler")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MICRONIX_PROJECT_ROOT
    "${CMAKE_CURRENT_LIST_DIR}/../.."
    CACHE PATH
    "Root directory of the micronix project")

find_package(Freetype REQUIRED)

add_executable(micronix-font-sample
    font_sample.cpp
)

target_include_directories(micronix-font-sample PRIVATE
    "${MICRONIX_PROJECT_ROOT}/include"
)

target_link_libraries(micronix-font-sample PRIVATE
    Freetype::Freetype
)
