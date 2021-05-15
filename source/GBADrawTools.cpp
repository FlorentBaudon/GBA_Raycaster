#include "GBA_VAR.h"

#include "GBADrawTools.h"

short make_color(char r, char g, char b)
{
	return ( (r & 0x1f) | (g & 0x1f) << 5 | (b & 0x1f) << 10);
}

// void put_pixel(volatile char* buffer, int x, int y, unsigned short color)
// {
// 	buffer[y*WIDTH+x] = color;
// }

void put_pixel(volatile short* buffer, int x, int y, char color) 
{
    /* find the offset which is the regular offset divided by two */
    short offset = (y * WIDTH + x) >> 1;

    /* read the existing pixel which is there */
    short pixel = buffer[offset];

    /* if it's an odd column */
    if (x & 1) {
        /* put it in the left half of the short */
        buffer[offset] = (color << 8) | (pixel & 0x00ff);
    } else {
        /* it's even, put it in the left half */
        buffer[offset] = (pixel & 0xff00) | color;
    }
}

void clear_screen(volatile short* buffer, char color) {
    for (short y = 0; y < HEIGHT; y++) {
        for (short x = 0; x < WIDTH; x++) {
            put_pixel(buffer, x, y, color);
        }
    }
}

char add_color(char r, char g, char b, int &index)
{
	short c = (r & 0x1f) | (g & 0x1f) << 5 | (b &0x1f) << 10;

	PALETTE[index] = c;

	index++;

	return index-1;

}

void draw_rect(volatile short* buffer, int posX, int posY, int width, int height, char color)
{
	for(int y=0; y<height; y++)
	{
		for(int x=0; x<width; x++)
		{
			put_pixel(buffer, posX + x, posY +y, color);
		}
	}
}

void draw_vert_line(volatile short* buffer, int start_x, int start_y, int en_x, int end_y, char color)
{

	for(int y=0; y< (end_y-start_y); y++)
	{
		put_pixel(buffer, start_x, start_y+y, color);
	}
}
