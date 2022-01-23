#include "GBA_VAR.h"

#include "GBADrawTools.h"

/******** M3 Mode ************/

// M3 mode use 16 bits color, but color only encore in 15 bits, 5 bit for each component (r, g, b)
unsigned short M3_make_color(unsigned char r, unsigned char g, unsigned char b)
{
	return ( (r & 0x1f) | (g & 0x1f) << 5 | (b & 0x1f) << 10);
}

// Draw a pixel in M3 mode, no double buffer (front buffer point to the begin of VRAM)
void M3_put_pixel(int x, int y, unsigned short color)
{
	FRONT_BUFFER[y*WIDTH+x] = color;
}

/******** M4 Mode ************/

// M4 mode use 16 bit colors, but the color is stored in 8bit value named palette. We need to add color to the palette before use them, VRAM use the 8bit value to retrieved the color. We are limited to 256 colors
unsigned char M4_add_color(unsigned char r, unsigned char g, unsigned char b, uint8 &index)
{
	unsigned short c = (r & 0x1f) | (g & 0x1f) << 5 | (b &0x1f) << 10;

	PALETTE[index] = c;

	index++;

	return index-1;

}

// M4 mode have double buffering, we give the current buffer, the position, and the index of the color in the palette. we store two color in 16 bits, if coloumn is odd we store the colore index in the end of the 16 bit word
void M4_put_pixel(volatile unsigned short* buffer, int x, int y, unsigned char color) 
{
    /* find the offset which is the regular offset divided by two */
    unsigned short offset = (y * WIDTH + x) >> 1;

    /* read the existing pixel which is there */
    unsigned short pixel = buffer[offset];

    /* if it's an odd column */
    if (x & 1) {
        /* put it in the left half of the unsigned short */
        buffer[offset] = (color << 8) | (pixel & 0x00ff);
    } else {
        /* it's even, put it in the left half */
        buffer[offset] = (pixel & 0xff00) | color;
    }
}

void M4_clear_screen(volatile unsigned short* buffer, unsigned char color) {
    for (unsigned short y = 0; y < HEIGHT; y++) {
        for (unsigned short x = 0; x < WIDTH; x++) {
            M4_put_pixel(buffer, x, y, color);
        }
    }
}

void draw_rect(volatile unsigned short* buffer, int posX, int posY, int width, int height, unsigned char color)
{
	for(int y=0; y<height; y++)
	{
		for(int x=0; x<width; x++)
		{
			M4_put_pixel(buffer, posX + x, posY +y, color);
		}
	}
}

void draw_vert_line(volatile unsigned short* buffer, int start_x, int start_y, int en_x, int end_y, unsigned char color)
{

	for(int y=0; y< (end_y-start_y); y++)
	{
		M4_put_pixel(buffer, start_x, start_y+y, color);
	}
}
