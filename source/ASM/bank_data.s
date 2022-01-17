@ gba library screen bank routines.
@ Pete (dooby@bits.bris.ac.uk)

	.global	gba_bank

	.section	.iwram, "w", %progbits
	.align
gba_bank:
	.word	0x00000001  		@ Current write bank (1 or 2).
	.word	0x06000000		@ Bank 1 address.
	.word	0x0600a000 		@ Bank 2 address.

	.END
