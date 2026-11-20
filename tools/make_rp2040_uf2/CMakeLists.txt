cmake_minimum_required(VERSION 4.3)
project(make_rp2040_uf2)

set(CMAKE_CXX_STANDARD 20)

add_executable(micronix-make-rp2040-uf2 make_uf2.cpp
        ../common/cpp/exception.h)
target_include_directories(micronix-make-rp2040-uf2 PRIVATE "../common")