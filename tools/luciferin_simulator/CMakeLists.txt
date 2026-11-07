cmake_minimum_required(VERSION 3.22)
project(micronix_luciferin_simulator LANGUAGES CXX)

if(NOT MSVC)
    message(FATAL_ERROR
        "luciferin-simulator must be configured with the Microsoft Visual C++ compiler")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MICRONIX_PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.."  CACHE PATH  "Root directory of the micronix project")

add_executable(micronix-luciferin-simulator
    simulator.cpp
)

target_include_directories(micronix-luciferin-simulator PRIVATE
    "${MICRONIX_PROJECT_ROOT}/include"
    "."
)

target_link_libraries(micronix-luciferin-simulator PRIVATE
    user32
    gdi32
)
