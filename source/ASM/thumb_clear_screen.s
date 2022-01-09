	.section	.iwram,"ax",%progbits
	.text
	.align 		2
	.code 		16
	.thumb_func
	.global		thumb_asm_clear_screen
	.type 		thumb_asm_clear_screen STT_FUNC

thumb_asm_clear_screen:
	@Function
	ldr r5, =#0x6000000
	ldr r6, =#0xFF
	ldr r7, =#0x9600

loop:
	strh r0, [r5]
	add r5,r5,#2
	sub r7, r7, #1
	bne loop

	bx lr @return to previous function
