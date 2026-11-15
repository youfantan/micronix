"""Generate register_spec.h from RP2040 SVD using only the Python standard library.

Usage: python svg_gen.py [input.svd] [-o output.h]
Defaults are rp2040.svd and register_spec.h beside this script.
Include the output in the same context as the STM32 register_spec.h, with
u32, RegisterFieldDescriptor and DECL_REGISTER already available.
Field members matching their enclosing register's name gain a trailing '_'.
"""

import argparse
from pathlib import Path
import re
import xml.etree.ElementTree as ET


# Matches micronix::access_type in include/base.h.
ACCESS = {"read-write": 0, "read-only": 1, "write-only": 2,
          "read-writeOnce": 3, "writeOnce": 4}


def identifier(name):
    name = re.sub(r"[^A-Za-z0-9_]", "_", name)
    return "_" + name if name[0].isdigit() else name


def field_bits(field):
    if field.find("bitOffset") is not None:
        return int(field.findtext("bitOffset"), 0), int(field.findtext("bitWidth"), 0)
    if field.find("bitRange") is not None:
        high, low = map(int, re.findall(r"\d+", field.findtext("bitRange")))
    else:
        low = int(field.findtext("lsb"), 0)
        high = int(field.findtext("msb"), 0)
    return low, high - low + 1


def parse_svd(source):
    root = ET.parse(source).getroot()
    peripherals = {p.findtext("name"): p for p in root.findall("./peripherals/peripheral")}

    def inherited(peripheral, tag):
        value = peripheral.find(tag)
        if value is not None:
            return value
        parent = peripheral.get("derivedFrom")
        return inherited(peripherals[parent], tag) if parent else None

    result = []
    for name, peripheral in peripherals.items():
        access = inherited(peripheral, "access")
        access = access.text if access is not None else root.findtext("access", "read-write")
        registers = []
        for register in inherited(peripheral, "registers"):
            reg_access = register.findtext("access", access)
            fields = []
            for field in register.findall("./fields/field"):
                offset, width = field_bits(field)
                fields.append((identifier(field.findtext("name")), offset, width,
                               ACCESS[field.findtext("access", reg_access)]))
            registers.append((identifier(register.findtext("name")),
                              int(register.findtext("addressOffset"), 0), fields))
        result.append((identifier(name), int(inherited(peripheral, "baseAddress").text, 0), registers))
    return result


def generate(peripherals):
    lines = ["#pragma once", ""]
    for peripheral, base, registers in peripherals:
        lines.append(f"constexpr static u32 {peripheral}_BASE = {base};")
        for register, offset, fields in registers:
            prefix = f"{peripheral}_{register}"
            lines.append(f"constexpr static u32 {prefix}_BASE = {peripheral}_BASE + {offset};")
            for field, bit, width, access in fields:
                lines.append(f"constexpr static RegisterFieldDescriptor {prefix}_{field} = "
                             f"{{ {bit}, {width}, {access} }};")
            lines.append("")
        lines.append("")

    for peripheral, _, registers in peripherals:
        lines.append(f"struct {peripheral} {{")
        for register, _, fields in registers:
            # Nested classes and data members cannot have their enclosing class's name.
            reg_type = register + "_" if register == peripheral else register
            lines.append(f"\tstruct {reg_type} {{")
            lines.append(f"\t\tDECL_REGISTER({peripheral}_{register}_BASE);")
            for field, _, _, _ in fields:
                member = field + "_" if field == reg_type else field
                lines.append(f"\t\tconstexpr static RegisterField<{peripheral}_{register}_{field}> {member} {{}};")
            lines.extend(["\t};", ""])
        lines.extend(["};", ""])
    return "\n".join(lines)


def main():
    directory = Path(__file__).resolve().parent
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("svd", nargs="?", type=Path, default=directory / "rp2040.svd")
    parser.add_argument("-o", "--output", type=Path, default=directory / "register_spec.h")
    args = parser.parse_args()
    peripherals = parse_svd(args.svd)
    args.output.write_text(generate(peripherals), encoding="utf-8", newline="\n")
    print(f"Generated {args.output}: {len(peripherals)} peripherals, "
          f"{sum(len(registers) for _, _, registers in peripherals)} registers")


if __name__ == "__main__":
    main()
