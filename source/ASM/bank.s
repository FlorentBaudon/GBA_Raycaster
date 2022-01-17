@ gba library screen bank routines.
@ Pete (dooby@bits.bris.ac.uk)

	.GLOBAL	gba_swapbank
	.GLOBAL	gba_initbank
	.GLOBAL	gba_setwbank
	.GLOBAL	gba_setdbank
	.GLOBAL	gba_vsync
	.extern	gba_bank

	.section	code, "x", %progbits
	.arm
	.align
	.text

@ void gba_vsync(void)@
@ To wait for a vsync, just keep checking the halfword at 0x04000006 until
@ it hits 0xa0.
@ Unfortunately my assembler doesn't cope with halfwords so I have to point
@ at the next-lowest word boundary...
@ Think I've fixed the bug where waiting for a vsync when already @ line 160
@ immediately exited, rather than waiting for /next/ vsync...
gba_vsync:
	mov	a1, #0x04000000		@ Point at word holding vcount.
gba_vsync_loop1:
	ldrh	a2, [a1, #6]		@ Get the whole word
	cmp	a2, #0x9f		@ Let's wait for pre-end line.
	bne	gba_vsync_loop1		@ /Then/ wait for end line...
gba_vsync_loop2:
	ldrh	a2, [a1, #6]		@ Load vcount.
	cmp	a2, #0xa0		@ Are we there yet?
	bne	gba_vsync_loop2		@ Nope - keep polling
	bx	lr			@ Done - return

@ Version of vsync which just exits if/when we're in VBLANK.
gba_vsync2:
	mov     a1, #0x04000000
gba_vsync_loop:
	ldrh    a2, [a1, #6]
	cmp     a2, #0xa0
	bne	gba_vsync_loop
	bx	lr

@ void gba_setdbank(byte n)@
@ Can be 0 or 1.
@ Sets current display bank. Only really useful for FX, normally call
@ gba_swapbuff()@
gba_setdbank:
	mov	a2, #0x04000000		@ Point at hardware.
	ldrh	a3, [a2]		@ Read flags.
	bic	a3, a3, #0x10		@ Drop the current display bank.
	orr	a3, a3, a1, lsl #4	@ Insert the new bank.
	strh	a3, [a2]		@ Store the bank back.
	bx	lr

@ void gba_setwbank(char b)@
@ Set which screen bank we're writing to (1 or 2).
gba_setwbank:
	ldr	a2, =gba_bank		@ Point at bank.

	@ldr	a2, =gba_bank_loc		@ Point at bank.
	@ldr	a2, [a2]

	strb	a1, [a2]		@ Store new bank.
	bx	lr

	.pool
@gba_bank_loc:
@	.word	gba_bank

@ void gba_initbank(void)@
@ Initialises ready for double buffer plotting.
@ Call this once, before any plotting.
gba_initbank:
	stmfd	sp!, {lr}	@ Need to store this since we call FNs :}
	mov	a1, #0		@ Set display bank.
	bl	gba_setdbank
	mov	a1, #2		@ Set write bank to other.
	bl	gba_setwbank
	ldmfd	sp!, {lr}	@ Return.
	bx	lr

@ void gba_swapbank(void)@
@ Swaps the screen banks - flips display & write banks.
@ Call this once a loop, after vsync for double buffering.
gba_swapbank:
	mov	a1, #0x04000000		@ Point at hardware.
	ldrh	a2, [a1]		@ Read flags.
	eor	a2, a2, #0x10		@ Flip display bank.
	strh	a2, [a1]		@ Store the bank back.
@ NB Need to flip write bank here too.
	ldr	a2, =gba_bank		@ Point at current bank variable.

	@ldr	a2, =gba_bank_loc	@ Point at current bank variable.
	@ldr	a2, [a2]

	ldrb	a1, [a2]		@ Read it.
	rsb	a1, a1, #3		@ Flip it.
	strb	a1, [a2]		@ Store it.
	bx	lr
	.pool
@gba_bank_loc2:
@	.word	gba_bank

	.END
