#include "GBA_VAR.h"

#include "GBADrawTools.h"

extern "C" void asm_clear_screen_m4(volatile uint16* buffer, uint16 color) CODE_IN_IWRAM;
extern "C" void asm_draw_line_m4(volatile uint16* buffer, uint8 color, uint16 x, uint16 y, uint16 endy) CODE_IN_IWRAM;

/******** M3 Mode ************/

// M3 mode use 16 bits color, but color only encore in 15 bits, 5 bit for each component (r, g, b)
uint16 M3_make_color(uint8 r, uint8 g, uint8 b)
{
	return ( (r & 0x1f) | (g & 0x1f) << 5 | (b & 0x1f) << 10);
}

// Draw a pixel in M3 mode, no double buffer (front buffer point to the begin of VRAM)
void M3_put_pixel(int x, int y, uint16 color)
{
	FRONT_BUFFER[y*WIDTH+x] = color;
}

/******** M4 Mode ************/

// M4 mode use 16 bit colors, but the color is stored in 8bit value named palette. We need to add color to the palette before use them, VRAM use the 8bit value to retrieved the color. We are limited to 256 colors
uint8 M4_add_color(uint8 r, uint8 g, uint8 b, int &index)
{
	uint16 c = (r & 0x1f) | (g & 0x1f) << 5 | (b &0x1f) << 10;

	PALETTE[index] = c;

	index++;

	return index-1;

}

// M4 mode have double buffering, we give the current buffer, the position, and the index of the color in the palette. we store two color in 16 bits, if coloumn is odd we store the colore index in the end of the 16 bit word
void M4_put_pixel(volatile uint16* buffer, int x, int y, uint8 color) 
{
    /* find the offset which is the regular offset divided by two */
    uint16 offset = (y * WIDTH + x) >> 1;

    /* read the existing pixel which is there */
    uint16 pixel = buffer[offset];

    /* if it's an odd column */
    if (x & 1) {
        /* put it in the left half of the uint16 */
        buffer[offset] = (color << 8) | (pixel & 0x00ff);
    } else {
        /* it's even, put it in the left half */
        buffer[offset] = (pixel & 0xff00) | color;
    }
}

void M4_clear_screen(volatile uint16* buffer, uint8 color) {
    for (uint16 y = 0; y < HEIGHT; y++) {
        for (uint16 x = 0; x < WIDTH; x++) {
            M4_put_pixel(buffer, x, y, color);
        }
    }
}

void ASM_draw_vert_line(volatile uint16* buffer, uint8 color, uint16 x, uint16 y, uint16 endy)
{
    asm_draw_line_m4(buffer, color, x, y, endy);
}

void ASM_clear_screen(volatile uint16* buffer, uint16 color)
{
    asm_clear_screen_m4(buffer, color);
}

void draw_rect(volatile uint16* buffer, int posX, int posY, int width, int height, uint8 color)
{
	for(int y=0; y<height; y++)
	{
		for(int x=0; x<width; x++)
		{
			M4_put_pixel(buffer, posX + x, posY +y, color);
		}
	}
}

void draw_vert_line(volatile uint16* buffer, int start_x, int start_y, int en_x, int end_y, uint8 color)
{

	for(int y=0; y< (end_y-start_y); y++)
	{
		M4_put_pixel(buffer, start_x, start_y+y, color);
	}
}
