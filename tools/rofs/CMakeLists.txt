cmake_minimum_required(VERSION 4.3)
project(micronix-rofs-collect)

set(CMAKE_CXX_STANDARD 20)

add_executable(micronix-rofs-collect)
target_sources(micronix-rofs-collect PRIVATE rofs_collect.cpp)
target_include_directories(micronix-rofs-collect PRIVATE ../common/cpp)
