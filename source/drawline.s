.global		asm_draw_line_m4

.section	.iwram,"ax",%progbits
.arm
.align 2
.text

@ === void asm_draw_line_m4(ushort buffer, uchar color, uint x, uint y, uint endy); =============
@ Reglist:
@  r0 : buffer
@  r1 : color
@  r2 : X coordinate of vertical line
@  r3 : Start Y coordinate
@  r4 : End Y coordinate

asm_draw_line_m4:
	
	@Nombre de ligne (resY ecran)
	mov r5, #160
	
	@Nombre de colonne (resX ecran)
	mov r6,#240
	
	@init start point
	mul r7, r3, r6		@convert Y start coodinate in byte number by multiple by X size (in byte)
	
	add r7, r7, r2		@ add x coordinate 
	add r0, r0, r7      @add result to VRAM address

    @ mov r4, #130
	sub r4, r4, r3 	@calculate length
    	
    @ AND r9, r2, #1 @check if column is odd 
	@ LSLEQ r1, r8, #8 @if odd shift color of 8 bit
	
	
loop:
	ldrh r8, [r0]

	ORR r8, r8, r1 @assemble les couleurs

	@On insère la valeur de R1 dans l'adresse contenue dans r0 et on ajoute à l'adresse r0 la valeur r3 après avoir stocké la valeur (post indexed offset)
	strh r8, [r0], r6
	@On passe à la ligne suivante en soustrayant 1 au nombre total de ligne, si == 0 le flag sera à 1
	subs r4, r4, #1
	@Si flag != 1 on recommence
	bne loop

    bx lr

