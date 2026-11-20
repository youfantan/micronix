set_project("micronix")
set_defaultplat("cross")
set_allowedplats("cross")
set_defaultarchs("arm")
set_defaultmode("debug")
set_languages("cxx20")

local rofs_image
function prebuild_paths(paths)
    rofs_image = path.absolute(paths.rofs_image, os.projectdir()):gsub("\\", "/")
end

includes("xmake/env.lua")
local sdk = sdk_paths
set_config("vcpkg", sdk.vcpkg)
set_config("sdk", sdk.armgcc)
set_config("cross", "arm-none-eabi-")
set_config("target_os", "none")

toolchain("armgcc")
    set_kind("standalone")
    set_bindir(path.join(sdk.armgcc, "bin"))
    set_toolset("cc", "arm-none-eabi-gcc")
    set_toolset("cxx", "arm-none-eabi-g++")
    set_toolset("as", "arm-none-eabi-gcc")
    set_toolset("ld", "arm-none-eabi-gcc")
    set_toolset("ar", "arm-none-eabi-ar")
    set_toolset("strip", "arm-none-eabi-strip")
toolchain_end()

option("device")
    set_default("rp2040")
    set_values("rp2040", "stm32g030")
    set_showmenu(true)
option_end()

add_rules("plugin.compile_commands.autoupdate", {outputdir = "."})

target("demoapp")
    set_toolchains("armgcc")
    set_kind("binary")
    set_extension(".elf")

    set_targetdir("$(builddir)/$(device)/$(mode)")

    set_objectdir("$(builddir)/.objs/$(device)/$(mode)")
    set_dependir("$(builddir)/.deps/$(device)/$(mode)")

    add_files("os/base.cpp", "os/kernel/*.cpp", "test/main.cpp")

    add_includedirs("include", "modules", "devices", "devices/$(device)")

    add_cxflags("-mcpu=cortex-m0plus", "-mthumb", "-ffreestanding", "-fno-builtin",
                "-Wall", "-fdata-sections", "-ffunction-sections", {force = true})

    add_cxxflags("-fno-rtti", "-fno-exceptions", "-fno-threadsafe-statics", "-fconcepts-diagnostics-depth=128", {force = true})

    add_asflags("-mcpu=cortex-m0plus", "-mthumb", {force = true})
    add_asflags('-DMICRONIX_ROFS_IMAGE_PATH="' .. rofs_image .. '"', {force = true})

    add_ldflags("-mcpu=cortex-m0plus", "-mthumb", "-nostdlib",
                "-Wl,--gc-sections", "-Wl,--print-memory-usage",
                "-Wl,-Map=$(builddir)/$(device)/$(mode)/micronix.map", {force = true})

    add_syslinks("gcc")

    if is_mode("release") then
        set_optimize("smallest")
    else
        set_optimize("none")
        set_symbols("debug")
    end

    if is_config("device", "rp2040") then
        includes("xmake/rp2040.lua")
    else
        includes("xmake/stm32g0.lua")
    end
target_end()
