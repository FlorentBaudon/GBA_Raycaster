#pragma once

uint16 M3_make_color(uint8 r, uint8 g, uint8 b);
void M3_put_pixel(int x, int y, uint16 color);
void M4_put_pixel(volatile uint16* buffer, int x, int y, uint8 color);
void M4_clear_screen(volatile uint16* buffer, uint8 color);
uint8 M4_add_color(uint8 r, uint8 g, uint8 b, int &index);

void ASM_draw_vert_line(volatile uint16* buffer, uint8 color, uint16 x, uint16 y, uint16 endy);
void ASM_clear_screen(volatile uint16* buffer, uint16 color);

void draw_rect(volatile uint16* buffer, int posX, int posY, int width, int height, uint8 color);
void draw_vert_line(volatile uint16* buffer, int start_x, int start_y, int en_x, int end_y, uint8 color);