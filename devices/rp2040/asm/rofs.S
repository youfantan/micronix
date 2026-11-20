.section .flushable, "a", %progbits
.balign 4

.global luciferin_flushable_start
.global luciferin_flushable_end

luciferin_flushable_start:
.incbin MICRONIX_ROFS_IMAGE_PATH
luciferin_flushable_end:
