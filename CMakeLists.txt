cmake_minimum_required(VERSION 3.22)
project(micronix LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(DEVICE_TYPE stm32g030 CACHE STRING "Target device")
set(DEVICE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/devices" CACHE PATH "Device support directory")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
message(STATUS "Selected Device: ${DEVICE_TYPE}")

# The top-level project is reserved for firmware and must use the ARM GCC
# toolchain selected by CMakePresets.json.
if(NOT CMAKE_C_COMPILER_ID STREQUAL "GNU" OR
   NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
   NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "arm")
    message(FATAL_ERROR
        "The micronix firmware target must be configured with cmake/gcc-arm-none-eabi.cmake")
endif()

add_executable(demoapp
        subsystem/luciferin/font.cpp
        devices/stm32g030/peripherals/periphals.h
        devices/stm32g030/peripherals/clock.h)

target_include_directories(demoapp PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/modules"
    "${DEVICE_DIR}"
    "${DEVICE_DIR}/${DEVICE_TYPE}"
)

target_sources(demoapp PRIVATE
    "${DEVICE_DIR}/${DEVICE_TYPE}/startup.s"
    os/kernel/os_entry.cpp
    os/kernel/slab_alloc.cpp
        os/base.cpp
    test/main.cpp
)

target_link_options(demoapp PRIVATE
    -T "${DEVICE_DIR}/${DEVICE_TYPE}/app.ld"
)

target_link_libraries(demoapp PRIVATE gcc)

# CMake cannot mix the ARM GCC and MSVC toolchains in one build tree. The
# Windows-only tools therefore have their own MSVC build trees, invoked from
# this project as external targets.
option(MICRONIX_BUILD_HOST_TOOLS "Build the MSVC host tools" ON)

if(MICRONIX_BUILD_HOST_TOOLS)
    include(ExternalProject)
    set(MICRONIX_VCPKG_ROOT "$ENV{VCPKG_ROOT}" CACHE PATH "vcpkg root used to resolve host-tool dependencies")
    set(MICRONIX_VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "vcpkg target triplet for host tools")
    set(MICRONIX_MSVC_GENERATOR "" CACHE STRING "Optional CMake generator for MSVC tools; empty uses CMake's default")

    function(micronix_add_msvc_tool tool_target source_dir build_target)
        set(tool_binary_dir
            "${CMAKE_CURRENT_BINARY_DIR}/host-tools/${tool_target}")
        set(tool_cmake_args
            "-DMICRONIX_PROJECT_ROOT=${CMAKE_CURRENT_SOURCE_DIR}"
            "-DCMAKE_BUILD_TYPE=$<CONFIG>"
        )
        set(tool_generator_args)

        if(MICRONIX_VCPKG_ROOT)
            file(TO_CMAKE_PATH
                "${MICRONIX_VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
                tool_vcpkg_toolchain)
            list(APPEND tool_cmake_args
                "-DCMAKE_TOOLCHAIN_FILE=${tool_vcpkg_toolchain}"
                "-DVCPKG_TARGET_TRIPLET=${MICRONIX_VCPKG_TARGET_TRIPLET}"
            )
        endif()

        if(MICRONIX_MSVC_GENERATOR)
            list(APPEND tool_generator_args
                "CMAKE_GENERATOR" "${MICRONIX_MSVC_GENERATOR}")
        endif()

        ExternalProject_Add(${tool_target}
            SOURCE_DIR "${source_dir}"
            BINARY_DIR "${tool_binary_dir}"
            ${tool_generator_args}
            CMAKE_ARGS ${tool_cmake_args}
            BUILD_COMMAND
                "${CMAKE_COMMAND}" --build <BINARY_DIR>
                --config $<CONFIG>
                --target ${build_target}
            INSTALL_COMMAND ""
            TEST_COMMAND ""
            UPDATE_COMMAND ""
        )
    endfunction()

    micronix_add_msvc_tool(
        micronix_font_sample
        "${CMAKE_CURRENT_SOURCE_DIR}/tools/font_sample"
        micronix-font-sample
    )

    micronix_add_msvc_tool(
        micronix_luciferin_simulator
        "${CMAKE_CURRENT_SOURCE_DIR}/tools/luciferin_simulator"
        micronix-luciferin-simulator
    )
endif()

list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)
