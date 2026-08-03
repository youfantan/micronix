set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Target CPU definition, can be overridden with -DMCU_FLAGS="..."
if(NOT DEFINED MCU_FLAGS)
  set(MCU_FLAGS "-mcpu=cortex-m0plus -mthumb -mfloat-abi=soft")
endif()

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_C_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_FLAGS   "${MCU_FLAGS} -Wall -Wextra -ffunction-sections -fdata-sections -nostdlib -std=c11")
set(CMAKE_CXX_FLAGS "${MCU_FLAGS} -Wall -Wextra -ffunction-sections -fdata-sections -nostdlib -std=c++17 -fno-exceptions")
set(CMAKE_ASM_FLAGS "${MCU_FLAGS} -x assembler-with-cpp")
