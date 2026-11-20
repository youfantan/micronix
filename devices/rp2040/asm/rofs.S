.section .flushable, "a", %progbits
.balign 4

.global _flash_rofs_image_begin
.global _flash_rofs_image_end

_flash_rofs_image_begin:
#embed MICRONIX_ROFS_IMAGE_PATH prefix(.byte )
_flash_rofs_image_end:
