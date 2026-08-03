cmake_minimum_required(VERSION 4.2)
project(micronix LANGUAGES C CXX ASM)

set(CMAKE_CXX_STANDARD 20)

set(DEVICE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/devices/stm32g030)
set(BOOTLOADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bootloader)
set(OS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/os)

add_executable(bootloader
    ${BOOTLOADER_DIR}/boot.cpp
    ${OS_DIR}/os_entry.cpp
    ${OS_DIR}/slab_alloc.cpp
    ${DEVICE_DIR}/startup.s
)

# device_spec.h lives in devices/stm32g030, public API in include/
target_include_directories(bootloader PRIVATE
    ${DEVICE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# MCU_FLAGS is a space-separated string; convert to a list for per-target use.
string(REPLACE " " ";" MCU_FLAGS_LIST "${MCU_FLAGS}")

target_compile_options(bootloader PRIVATE ${MCU_FLAGS_LIST})

target_link_options(bootloader PRIVATE
    ${MCU_FLAGS_LIST}
    -T ${DEVICE_DIR}/bootloader.ld
    -Wl,--gc-sections
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/bootloader.map
)

set_target_properties(bootloader PROPERTIES
    OUTPUT_NAME bootloader
    SUFFIX ""
)

add_custom_command(TARGET bootloader POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex   $<TARGET_FILE:bootloader> ${CMAKE_CURRENT_BINARY_DIR}/bootloader.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:bootloader> ${CMAKE_CURRENT_BINARY_DIR}/bootloader.bin
    VERBATIM
)

# ---------------------------------------------------------------------------
# STM32G030 application (OS + user code, linked at 0x08001800)
# ---------------------------------------------------------------------------
add_executable(app
    ${OS_DIR}/os_entry.cpp
    ${OS_DIR}/slab_alloc.cpp
    ${OS_DIR}/sched.cpp
    ${OS_DIR}/exception.cpp
)

# device_spec.h lives in devices/stm32g030, public API in include/
target_include_directories(app PRIVATE
    ${DEVICE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(app PRIVATE ${MCU_FLAGS_LIST})

target_link_options(app PRIVATE
    ${MCU_FLAGS_LIST}
    -T ${DEVICE_DIR}/app.ld
    -Wl,--gc-sections
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/app.map
)

# Keep a clean ELF name (no platform executable suffix).
set_target_properties(app PROPERTIES
    OUTPUT_NAME app
    SUFFIX ""
)

# Generate flashable artifacts (Intel HEX and raw binary) from the ELF.
add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex   $<TARGET_FILE:app> ${CMAKE_CURRENT_BINARY_DIR}/app.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:app> ${CMAKE_CURRENT_BINARY_DIR}/app.bin
    VERBATIM
)
