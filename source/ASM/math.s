.global		asm_sqrt

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

