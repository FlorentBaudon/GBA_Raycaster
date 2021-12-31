	@ .section	.iwram,"ax",%progbits
	@ .text
	@ .align 		2
	@ .code 		16
	@ .thumb_func
	@ .global		asm_clear_screen
	@ .type 		asm_clear_screen STT_FUNC

	
	
	.global		asm_clear_screen
	.section	.iwram,"ax",%progbits
	.arm
	.align 2
	.text

	@les 2 ene^tete fonctionnent avec DevKitPro

asm_clear_screen:

	@ push    {r4, lr}

	mov r5, #0x6000000
	mov r6, #0xFF
	mov r7, #0x9600

loop:
	strh r6, [r5]
	add r5,r5,#2
	sub r7, r7, #1
	bne loop

    @ pop     {r4}
    @ pop     {r3}
    @ bx  r3
