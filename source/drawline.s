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
@  Stack : End Y coordinate

asm_draw_line_m4:
	@-----------prologue---
	mov ip, sp
	stmfd	sp!,{r4-r11}
	ldr r4, [ip]
	@----------------------

	

	@Nombre de ligne (resY ecran)
	mov r5, #160
	
	@Nombre de colonne (resX ecran)
	mov r6,#240

	@ We writing two 8bits word in 16bits, each represent a colum, we need to check if the colum is odd or not (see how mode 4 works for more details or Put pixel fonction in GBADrawTool.cpp)

	mov r10, #0xff00 @Mask to prevent overwriteing other date (we combine two column color in 16bit data, we when write on a a part, we don't wan't to erase the other)
    ANDS r9, r2, #1 @check if column is odd 
	SUBNE r2, r2, #1 @Remove one from colum number, the odd colum is stocked side by side with even, so we use the address of even column to store odd
	LSLNE r1, r1, #8 @if odd shift color of 8 bit
	LSRNE r10, r10, #8 @if odd shift mask

	
	@Calcultate start point in offset
	mul r7, r3, r6		@convert Y start coodinate in byte number by multiple by X size (in byte)
	add r7, r7, r2		@ add x coordinate 

	add r0, r0, r7      @add result to VRAM address

    @ mov r4, #130
	sub r4, r4, r3 	@calculate length
	
	
loop:
	ldrh r8, [r0]
	and r8, r8, r10
	ORR r8, r8, r1 @assemble les couleurs

	@On insère la valeur de R1 dans l'adresse contenue dans r0 et on ajoute à l'adresse r0 la valeur r3 après avoir stocké la valeur (post indexed offset)
	strh r8, [r0], r6
	@On passe à la ligne suivante en soustrayant 1 au nombre total de ligne, si == 0 le flag sera à 1
	subs r4, r4, #1
	@Si flag != 1 on recommence
	bne loop

	@-----------epilogue---
	ldmfd	sp!,{r4-r11}
    bx lr
	@----------------------

