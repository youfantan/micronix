cmake_minimum_required(VERSION 3.22)
project(micronix_luciferin_simulator CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT WIN32)
    message(FATAL_ERROR "The Luciferin simulator requires Windows (Win32/GDI).")
endif()

add_executable(micronix-luciferin-simulator simulator.cpp mock/platform.cpp)
target_include_directories(micronix-luciferin-simulator PRIVATE ../../include .)
target_link_libraries(micronix-luciferin-simulator PRIVATE user32 gdi32)
target_compile_definitions(micronix-luciferin-simulator PRIVATE
    NOMINMAX WIN32_LEAN_AND_MEAN
    MICRONIX_ROFS_IMAGE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/../../rofs.image.bin")
if(MSVC)
    target_compile_options(micronix-luciferin-simulator PRIVATE /utf-8)
endif()

include(CTest)
if(BUILD_TESTING)
    add_test(NAME simulator-smoke COMMAND micronix-luciferin-simulator --smoke-test)
endif()
