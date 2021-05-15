#include "GBA_VAR.h"

uint16 make_color(unsigned char r, unsigned char g, unsigned char b)
{	
	return ( (r & 0x1f) | (g & 0x1f) << 5 | (b & 0x1f) << 10);
}

void put_pixel(int x, int y, unsigned short color)
{
	SCREENBUFFER[y*WIDTH+x] = color;
}

void draw_rect(int left, int top, int width, int height, uint16 color) 
{
	for(int y=0; y<height; y++) 
	{
		for(int x=0; x<width; x++) 
		{
			SCREENBUFFER[(top + y) * WIDTH + left + x] = color;
		}
	}
}

void clear_screen() {
    /* set each pixel black */
    for (unsigned short row = 0; row < HEIGHT; row++) { 
        for (unsigned short col = 0; col < WIDTH; col++) {
            put_pixel(col, row, 0);
        }
    }
}

void vsync()
{
	while(VCOUNT>=160);
	while(VCOUNT<160);
}

int _main()
{
	DISPLAYCONTROL = MODE3 | BG2;

	int pX = 10;
	int pY = 50;
	int size = 10;
	
	uint16 bg_color = make_color(31, 0, 0);
	uint16 player_color = make_color(31, 31, 0);
	
	for (int i = 0; i < WIDTH * HEIGHT; i++)
	{
		SCREENBUFFER[i] = bg_color;
	}

	int x = 0;
	while(1)
	{
		vsync();
		
		//Clean previous
		draw_rect(pX,pY, size, size, bg_color);

		if ((KEYSTATE & 64) == 0) 
		{
			pY--;
		}
		if ((KEYSTATE & 128) == 0) 
		{
			pY++;
		}
		
		draw_rect(pX,pY, size, size, player_color);
	}
}

