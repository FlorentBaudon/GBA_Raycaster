.global		asm_clear_screen_m3
.global		asm_clear_screen_m4

.section	.iwram,"ax",%progbits
.arm
.align 2
.text

@ === void asm_clear_screen_m3(uShort color); =============
@ Reglist:
@  r0 : 16 bits color
asm_clear_screen_m3:
	@Function
	mov r5, #0x6000000
	mov r6, #0x9600

loop1:
	strh r0, [r5]
	add r5,r5,#2
	subs r6, r6, #1
	bne loop1

	bx lr @return to previous function

@ === void asm_clear_screen_m4(void *currentbuffer, uchar color); =============
@ Reglist:
@  r0 : Current VRAM buffer
@  r1 : 8bits  Color index
asm_clear_screen_m4:
	@buffer size
	mov r2, #0x4B00
	@in m4 mode color are stored using 8 bit index, we store two color index in 16 bit slot
	mov r3, r1
	LSL r3, #8
	ADD r3, r3,r1

loop2:
	strh r3, [r0]
	add r0,r0,#2
	subs r2, r2, #1
	bne loop2

	bx lr @return to previous function

	@r0 vram address - r1 color value
