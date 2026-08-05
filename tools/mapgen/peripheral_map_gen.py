#!/usr/bin/env python3

import argparse
import sys

ACCESS_RW = 0
ACCESS_NAMES = {0: "rw", 1: "r", 2: "w", 3: "rs"}
ACCESS_MAP = {
    "rw": 0,
    "r": 1,
    "w": 2,
    "rs": 3
}

class Field:
    def __init__(self, name, off, length, access):
        self.name = name
        self.off = int(off)
        self.length = int(length)
        code = ACCESS_MAP.get(access)
        if code is None:
            print(f"warning: unknown access '{access}' for field '{name}', "
                  f"mapped to 'rw'", file=sys.stderr)
            code = ACCESS_RW
        self.access = code

    @property
    def access_name(self):
        return ACCESS_NAMES[self.access]


class Register:
    def __init__(self, name, off):
        self.name = name
        self.off = off
        self.fields = []


class Peripheral:
    def __init__(self, name, base):
        self.name = name
        self.base = base
        self.registers = []


def _strip_quotes(token):
    return token.strip().strip("'")

def _parse_addr(token):
    return int(token.strip().lstrip("+"), 16)

def _clone_register(r):
    nreg = Register(r.name, r.off)
    for f in r.fields:
        nreg.fields.append(Field(f.name, f.off, f.length, ACCESS_NAMES[f.access]))
    return nreg


def parse_spec(peripherals, path):

    current = None
    with open(path, "r", encoding="utf-8") as f:
        for lineno, line in enumerate(f, 1):
            line = line.strip()
            if not line:
                continue

            parts = line.split()
            if parts[0] == "Peripheral":
                if len(parts) < 4 or parts[2] != "@":
                    raise ValueError(f"{path}:{lineno}: bad Peripheral line: {line!r}")
                if len(parts) >= 5 and parts[4] != "alt":
                    raise ValueError(f"{path}:{lineno}: bad Peripheral line: {line!r}")
                current = Peripheral(_strip_quotes(parts[1]), _parse_addr(parts[3]))
                if len(parts) == 6:
                    alt_name = _strip_quotes(parts[5])
                    src = next((p for p in peripherals if p.name == alt_name), None)
                    if src is None:
                        raise ValueError(
                            f"{path}:{lineno}: alt peripheral '{alt_name}' must be "
                            f"fully declared before '{current.name}'")
                    for r in src.registers:
                        current.registers.append(_clone_register(r))
                peripherals.append(current)
                continue

            if current is None:
                raise ValueError(f"{path}:{lineno}: '{line}' before any Peripheral")

            if parts[0] == "Register":
                if len(parts) < 3:
                    raise ValueError(f"{path}:{lineno}: bad Register line: {line!r}")
                current.registers.append(
                    Register(_strip_quotes(parts[1]), _parse_addr(parts[2])))
                continue

            if parts[0] == "Field":
                if not current.registers:
                    raise ValueError(f"{path}:{lineno}: '{line}' before any Register")
                if " " not in line:
                    raise ValueError(f"{path}:{lineno}: bad Field line: {line!r}")
                fields = line[line.index(" ") + 1:].split(",")
                if len(fields) < 4:
                    raise ValueError(f"{path}:{lineno}: bad Field line: {line!r}")
                current.registers[-1].fields.append(
                    Field(_strip_quotes(fields[0]), fields[1], fields[2], fields[3]))
                continue

            raise ValueError(f"{path}:{lineno}: cannot parse line: {line!r}")
    return peripherals


def main():
    parser = argparse.ArgumentParser(
        description="Parse register_spec files into structured data.")
    parser.add_argument("spec", nargs="*", default=["register_spec"],
                        help="input spec file(s); default: register_spec")
    args = parser.parse_args()
    peripherals = []
    for path in args.spec:
        parse_spec(peripherals, path)

    for p in peripherals:
        print(f"constexpr static uint32_t {p.name}_BASE = {p.base};")
        for r in p.registers:
            print(f"constexpr static uint32_t {p.name}_{r.name}_BASE = {p.name}_BASE + {r.off};")
            for f in r.fields:
                print(f"constexpr static RegisterFieldDescriptor {p.name}_{r.name}_{f.name} = {{ {f.off}, {f.length} }};")
            print("\n")
        print("\n")
    for p in peripherals:
        print(f"struct {p.name} {{")
        for r in p.registers:
            print(f"\tstruct {r.name} {{")
            print(f"\t\tDECL_REGISTER({p.name}_{r.name}_BASE);")
            for f in r.fields:
                print(f"\t\tconstexpr static RegisterField<{p.name}_{r.name}_{f.name}> {f.name} {{}};")
            print("\t};\n")
        print("};\n")
if __name__ == "__main__":
    main()
