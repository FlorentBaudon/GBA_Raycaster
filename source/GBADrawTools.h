short make_color(char r, char g, char b);
void put_pixel(volatile short* buffer, int x, int y, unsigned short color);
void clear_screen(volatile short* buffer, char color);
char add_color(char r, char g, char b, int &index);

void draw_rect(volatile short* buffer, int posX, int posY, int width, int height, char color);
void draw_vert_line(volatile short* buffer, int start_x, int start_y, int en_x, int end_y, char color);