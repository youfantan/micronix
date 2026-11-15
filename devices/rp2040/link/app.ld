ENTRY(_stage2)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x10000000, LENGTH = 2M
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 264K
}

SECTIONS
{
    .stage2 ORIGIN(FLASH) :
    {
        KEEP(*(.stage2))
        . = 0x100;
    } > FLASH

    .vectors :
    {
        KEEP(*(.vectors))
    } > FLASH

    .text :
    {
        *(.text .text.*)
        *(.rodata .rodata.*)
        . = ALIGN(4);
    } > FLASH

    .data :
    {
        . = ALIGN(4);
        _ram_data_begin = .;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _ram_data_end = .;
    } > RAM AT> FLASH

    _flash_data_begin = LOADADDR(.data);

    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _ram_bss_begin = .;

        *(.bss .bss.*)
        *(COMMON)

        . = ALIGN(4);
        _ram_bss_end = .;
    } > RAM

    .stack ORIGIN(RAM) + LENGTH(RAM) - 8K (NOLOAD) :
    {
        _StackBottom = .;
        . += 8K;
        _StackTop = .;
    } > RAM

    ASSERT(_stage2_end - ADDR(.boot2) <= 252,
           "Stage2 exceeds 252 bytes")
    ASSERT(SIZEOF(.boot2) == 256,
           "Boot2 must be 256 bytes")
    ASSERT(_ram_bss_end <= _StackBottom,
           "RAM data overlaps stack")
}