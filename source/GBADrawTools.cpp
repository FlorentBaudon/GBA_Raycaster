#include "GBA_VAR.h"

#include "GBADrawTools.h"

unsigned short make_color(unsigned char r, unsigned char g, unsigned char b)
{
	return ( (r & 0x1f) | (g & 0x1f) << 5 | (b & 0x1f) << 10);
}

void M3_put_pixel(volatile unsigned char* buffer, int x, int y, unsigned short color)
{
	buffer[y*WIDTH+x] = color;
}

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

void clear_screen(volatile unsigned short* buffer, unsigned char color) {
    for (unsigned short y = 0; y < HEIGHT; y++) {
        for (unsigned short x = 0; x < WIDTH; x++) {
            M4_put_pixel(buffer, x, y, color);
        }
    }
}

unsigned char add_color(unsigned char r, unsigned char g, unsigned char b, int &index)
{
	unsigned short c = (r & 0x1f) | (g & 0x1f) << 5 | (b &0x1f) << 10;

	PALETTE[index] = c;

	index++;

	return index-1;

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
