.syntax unified
.cpu cortex-m0plus
.thumb

.section .stage2, "ax", %progbits
.thumb_func
.global _stage2
_stage2:
@ Configure SSI
    ldr r3, =0x18000000
    movs r1, #0x00 @ SSI_EN -> 0
    str r1, [r3, #0x08] @ SSI_ENR

    ldr r1, =0x001f0300 @ DFS/FRF not used; SCPH -> 0; SCPOL -> 0; TMOD -> EEPROM_READ; SLV_OE/SRL not used; CFS -> 0(1 frame); DFS_32 -> 31(32 bits per frame); SPI_FRF -> Standard SPI
    str r1, [r3] @ @ SSI_CTRLR0

    movs r1, #0x00 @ NDF -> 0x00(FIFO only store 1 dataframe)
    str r1, [r3, #0x04] @ SSI_CTRLR1

    movs r1, #4 @ Generic 03h reads at clk_sys / 4
    str r1, [r3, #0x14] @ SSI_BAUDR

    ldr r4, =0xf4
    add r4, r3, r4
    ldr r1, =0x03000218 @ Serial 03h read, 8-bit command, 24-bit address, no dummy cycles
    str r1, [r4] @ SPI_CTRLR0

    movs    r1, #0x01 @ SSI_EN -> 1
    str     r1, [r3, #0x08] @ SSI_ENR
@ Configure Vector Table
    ldr r0, =_vectors
    ldr r2, [r0, #0x04] @ Load Reset Handler address into r2
    bx r2 @ Jump to reset handler
    .ltorg @ Reserved area

.section .vectors, "a", %progbits
.align 2
.global _vectors
_vectors:
    .word _stack_top
    .word Reset_Handler
    .rept 14
    .word Default_Handler
    .endr
    .rept 26
    .word Default_Handler
    .endr

.section .text, "ax", %progbits
.thumb_func
.align 2
.global Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    cpsid i
    ldr r0, =0xd0000000 @ SIO_BASE
    ldr r0, [r0] @ Get CPUID
    cmp r0, #0
    bne InfLoop @ only Core 0 work for initialize, now let it infinite loop

    ldr r0, =_vectors
    ldr r1, =0xe000ed08 @ SCB_VTOR
    str r0, [r1] @ Load VTB into SCB_VTOR
    ldr r1, [r0] @ Load Stack Top address into r1
    msr msp, r1 @ Set SP register to r1

    ldr r0, =_ram_data_begin
    ldr r1, =_ram_data_end
    ldr r2, =_flash_data_begin
1:  @ Copy .data from flash to RAM
    cmp r0, r1
    bhs 2f
    ldmia r2!, {r3}
    stmia r0!, {r3}
    b 1b
2:  @ Zero .bss
    ldr r0, =_ram_bss_begin
    ldr r1, =_ram_bss_end
    movs r3, #0
3:
    cmp r0, r1
    bhs 4f
    stmia r0!, {r3}
    b 3b
4:  @ Initialize Kernel
    bl clock_init
    bl kernel_entry
.thumb_func
Default_Handler:
InfLoop:
    wfi
    b InfLoop
