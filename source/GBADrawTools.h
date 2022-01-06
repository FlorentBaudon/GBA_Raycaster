#pragma once

unsigned short M3_make_color(unsigned char r, unsigned char g, unsigned char b);
void M3_put_pixel(int x, int y, unsigned short color);
void M4_put_pixel(volatile unsigned short* buffer, int x, int y, unsigned char color);
void M4_clear_screen(volatile unsigned short* buffer, unsigned char color);
unsigned char M4_add_color(unsigned char r, unsigned char g, unsigned char b, int &index);

void draw_rect(volatile unsigned short* buffer, int posX, int posY, int width, int height, unsigned char color);
void draw_vert_line(volatile unsigned short* buffer, int start_x, int start_y, int en_x, int end_y, unsigned char color);