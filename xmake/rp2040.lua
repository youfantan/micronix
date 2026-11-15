local sdk = sdk_paths

target("demoapp")
add_files("$(projectdir)/devices/rp2040/device.cpp", "$(projectdir)/devices/rp2040/asm/boot.S")
add_files("$(projectdir)/devices/rp2040/asm/rofs.S", {rule = "rp2040.rofs"})
add_defines("MICRONIX_DEVICE_RP2040=1")
add_defines('MICRONIX_FLUSHABLE_PATH="' .. path.join(os.projectdir(), "tools/luciferin_simulator/flushable.bin"):gsub("\\", "/") .. '"')
add_ldflags("-T$(projectdir)/devices/rp2040/link/app.ld", {force = true})

on_load(function (target)
    target:data_set("linkdepfiles", {path.join(os.projectdir(), "devices/rp2040/link/app.ld")})
end)

after_link(function (target)
    local image = path.join(target:targetdir(), target:basename())
    os.vrunv(sdk.python, {"devices/rp2040/link/makesum.py", "--elf", target:targetfile(),
        "--bin", image .. ".bin", "--objcopy", path.join(sdk.armgcc, "bin/arm-none-eabi-objcopy.exe")})
    os.vrunv(sdk.picotool, {"uf2", "convert", target:targetfile(), image .. ".uf2", "--family", "rp2040"})
end)

rule("rp2040.rofs")
    add_deps("asm.build")
    after_build_file(function (target, sourcefile)
        import("core.project.depend")
        local depfile = target:dependfile(target:objectfile(sourcefile))
        local info = depend.load(depfile)
        info.files = table.unique(table.join(info.files,
            {path.join(os.projectdir(), "tools/luciferin_simulator/flushable.bin")}))
        depend.save(info, depfile)
    end)
rule_end()
