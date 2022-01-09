.global		asm_sqrt
.global     asmgba_sin

.section	.iwram,"ax",%progbits
.arm
.align 2
.text


@ === uint asm_sqrt(uint x); =============
@ Reglist:
@  r0 : value to square root
asm_sqrt :
    swi 0x080000
    bx lr

@ s32 gba_sin(s32 angle)

asmgba_sin:
	mov		r0, r0, lsr #5
	mov		r0, r0, lsl #1
@	ldr		r1, =a_sin_table

	cmp		r0, #180 * 16
	bgt		2f

	cmp		r0, #90 * 16
	bgt		1f

	@ first quadrant (0 < a < 90)
	ldrh	r0, [r1, r0]
	b			9f
	
1:
	@ second quadrant (90 < a < 180)
	rsb		r0, r0, #180*16
	ldrh	r0, [r1, r0]
	b			9f

2:
	sub		r0, r0, #180*16
	cmp		r0, #90 * 16
	bgt		3f

	@ third quadrant (180 < a < 270)
	ldrh	r0, [r1, r0]
	rsb		r0, r0, #0
	b			9f

3:
	rsb		r0, r0, #180*16
	ldrh	r0, [r1, r0]
	rsb		r0, r0, #0
	
9:
	bx	lr

