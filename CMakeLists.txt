cmake_minimum_required(VERSION 3.22)
project(micronix C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(DEVICE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/devices/stm32g030/)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(app-test)

include_directories(
        include
        ${DEVICE_DIR})

target_sources(app-test PRIVATE
        ${DEVICE_DIR}/startup.s
        os/os_entry.cpp
        os/exception.cpp
        os/sched.cpp
        os/slab_alloc.cpp
        test/main.c
)

target_link_options(app-test PRIVATE
        -T ${DEVICE_DIR}/app.ld
)

list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)
