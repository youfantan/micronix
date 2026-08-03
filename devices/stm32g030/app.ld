/* Application linker script for STM32G030C8 (arm-none-eabi)
 *
 * Flash layout (64 KB total):
 *   0x08000000 - 0x080007FF   bootloader code       (2 KB, 1 page)
 *   0x08000800 - 0x080017FF   NVS shared page       (4 KB, 2 pages, bootloader + app)
 *   0x08001800 - 0x0800FFFF   application           (58 KB)
 *
 * The application vector table must be relocated to __APP_BASE__ (0x08001800)
 * with SCB->VTOR before enabling interrupts.
 *
 * RAM: 8 KB at 0x20000000.
 */

ENTRY(Reset_Handler)

_estack = ORIGIN(RAM) + LENGTH(RAM);    /* end of RAM, initial stack pointer */

MEMORY
{
  FLASH_APP (rx)  : ORIGIN = 0x08001800, LENGTH = 58K
  FLASH_NVS (r)   : ORIGIN = 0x08000800, LENGTH = 4K
  RAM       (xrw) : ORIGIN = 0x20000000, LENGTH = 8K
}

/* Shared layout constants, referenced from C code. */
__NVS_BASE__   = ORIGIN(FLASH_NVS);
__NVS_SIZE__   = LENGTH(FLASH_NVS);
__NVS_END__    = ORIGIN(FLASH_NVS) + LENGTH(FLASH_NVS);
__APP_BASE__   = ORIGIN(FLASH_APP);

/* Minimum amount of stack/heap reserved so a link error is raised when the
 * sections do not fit into RAM. */
_Min_Heap_Size  = 0x200;
_Min_Stack_Size = 0x400;

SECTIONS
{
  /* The startup code into "FLASH_APP" Rom type memory */
  .isr_vector :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector))         /* Startup code */
    . = ALIGN(4);
  } >FLASH_APP

  /* The program code and other data into "FLASH_APP" Rom type memory */
  .text :
  {
    . = ALIGN(4);
    *(.text)                     /* .text sections (code) */
    *(.text*)                    /* .text* sections (code) */
    *(.glue_7)                   /* glue arm to thumb code */
    *(.glue_7t)                  /* glue thumb to arm code */
    *(.eh_frame)

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;                  /* define a global symbols at end of code */
  } >FLASH_APP

  /* Constant data into "FLASH_APP" Rom type memory */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)                   /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)                  /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH_APP

  .ARM.extab   : { *(.ARM.extab* .gnu.linkonce.armextab.*) } >FLASH_APP
  .ARM : {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
  } >FLASH_APP

  .preinit_array :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } >FLASH_APP

  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } >FLASH_APP

  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } >FLASH_APP

  /* Used by the startup to initialize data */
  _sidata = LOADADDR(.data);

  /* Initialized data sections into "RAM" Ram type memory */
  .data :
  {
    . = ALIGN(4);
    _sdata = .;                  /* create a global symbol at data start */
    *(.data)                     /* .data sections */
    *(.data*)                    /* .data* sections */

    . = ALIGN(4);
    _edata = .;                  /* define a global symbol at data end */
  } >RAM AT> FLASH_APP

  /* Uninitialized data section into "RAM" Ram type memory */
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss section */
    _sbss = .;                   /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .;                   /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM

  /* User_heap_stack section, used to check that there is enough "RAM" RAM memory left */
  ._user_heap_stack :
  {
    . = ALIGN(8);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >RAM

  /* Remove information from the standard libraries */
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }
}
