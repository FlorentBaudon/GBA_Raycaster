#include "GBA_VAR.h"

#include "MathTools.h"
#include "GBADrawTools.h"
#include "Player.h"
#include "Raycaster.h"

#include <stdio.h>
#include <stdlib.h>

using namespace gba;

extern "C" void asm_clear_screen_m4(volatile unsigned short* buffer, unsigned char color) CODE_IN_IWRAM;
extern "C" void asm_draw_line_m4(volatile unsigned short* buffer, unsigned char color, unsigned short x, unsigned short y, unsigned short endy) CODE_IN_IWRAM;

vec2 world_forward = vec2(1,0);
vec2 world_right = vec2(0, 1);
float fov = DEG2RAD(60.f);

/********* Player **********/
Player* player = new Player(vec2(288, 150), world_forward, world_right, DEG2RAD(-90.f));
// Player* player = new Player(vec2(250, 250), world_forward, world_right, DEG2RAD(0));

//Map
uint8 mapX = 8, mapY = 8, mapS = 64, gridS = 1;
uint8 map[] =
{
1,1,1,1,2,1,1,1,
1,0,0,0,0,0,0,1,
1,0,1,0,0,0,0,1,
1,0,1,0,0,2,2,2,
1,0,0,0,0,0,0,1,
1,1,1,3,0,2,2,2,
1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1
};

// int map[] =
// {
// 1,1,1,1,1,1,1,1,
// 1,0,0,1,1,0,0,1,
// 1,0,0,0,0,0,0,1,
// 1,3,0,0,0,0,2,1,
// 1,3,0,0,0,0,2,1,
// 1,0,0,0,0,0,0,1,
// 1,0,0,1,1,0,0,1,
// 1,1,1,1,1,1,1,1
// };

/********* Raycaster **********/
Raycaster* raycaster;


unsigned volatile short* swap_buffer(unsigned volatile short* buffer_to_show)
{
	//On affiche le buffer dans lequel on a ecrit precedentment et on retourne l'autre buffer pour ecrire dedans au prochain cycle
	if(buffer_to_show == FRONT_BUFFER)
	{
		DISPLAYCONTROL &= ~SHOW_BACK;
		return BACK_BUFFER;
	}else
	{
		DISPLAYCONTROL |= SHOW_BACK;
		return FRONT_BUFFER;
	}
}

void vblank()
{
	while(VCOUNT<160) {};
}

bool process_input (Player* p) 
{
		float speed = 5.0f;
		vec2 d = vec2(0, 0);
		bool bMoved = false;

		if ((KEYSTATE & KEY_UP) == 0)
		{
			d.x+=speed;
			bMoved = true;
		}
		if ((KEYSTATE & KEY_DOWN) == 0)
		{
			d.x-=speed;
			bMoved = true;
		}
		if ((KEYSTATE & KEY_LEFT) == 0)
		{

			player->turn(  DEG2RAD(10.0f) );
			bMoved = true;
		}
		if ((KEYSTATE & KEY_RIGHT) == 0)
		{
			player->turn( -DEG2RAD(10.0f) );
			bMoved = true;
		}

		player->move(d);

		return bMoved;
}

int main()
{
	DISPLAYCONTROL = MODE4 | BG2;

	raycaster = new Raycaster(mapS, map, mapX, mapY, fov, WIDTH, HEIGHT);

	uint8 next_palette_index = 0;

	uint8 black = M4_add_color(0,0,0, next_palette_index);
	uint8 white = M4_add_color(31,31,31, next_palette_index);
	uint8 dark_white = M4_add_color(26,26,26, next_palette_index);
	uint8 green = M4_add_color(0,31,0, next_palette_index);
	uint8 dark_green = M4_add_color(0,20,0, next_palette_index);
	uint8 red = M4_add_color(31,0,0, next_palette_index);
	uint8 dark_red = M4_add_color(20,0,0, next_palette_index);
	uint8 blue = M4_add_color(0,0,31, next_palette_index);
	uint8 dark_blue = M4_add_color(0,0,20, next_palette_index);

	unsigned volatile short* current_buffer = FRONT_BUFFER;

	asm_clear_screen_m4(FRONT_BUFFER, black);
	asm_clear_screen_m4(BACK_BUFFER, black);

	uint16 pX = 20, pY = 10;

	while(1)
	{
		process_input(player);

		asm_clear_screen_m4(current_buffer, dark_blue);
		raycaster->scanEnv(current_buffer, player->position, player->angle);

		vblank();

		current_buffer = swap_buffer(current_buffer);
	}

}
