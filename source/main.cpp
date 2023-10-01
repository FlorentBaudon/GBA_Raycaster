#include "MathTools.h"

#include "GBA_VAR.h"
#include "GBADrawTools.h"
#include "Player.h"
#include "Raycaster.h"

using namespace m_gba;

extern "C" void asm_clear_screen_m4(volatile uint16* buffer, uint16 color) CODE_IN_IWRAM;
extern "C" void asm_draw_line_m4(volatile uint16* buffer, uint8 color, uint16 x, uint16 y, uint16 endy) CODE_IN_IWRAM;


vec2 world_forward = vec2(1,0);
vec2 world_right = vec2(0, 1);
float fov = DEG2RAD(60.f);

/********* Player **********/
Player* player = new Player(vec2(288, 70), world_forward, world_right, DEG2RAD(-90.f));

//Map
int mapX = 8, mapY = 8, mapS = 64, gridS = 1;
int map[] =
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

/********* Raycaster **********/
Raycaster* raycaster;


volatile uint16* swap_buffer(volatile uint16* buffer_to_show)
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

void process_input (Player* p) 
{
		float s = 5.0f;
		vec2 d = vec2(0, 0);

		if ((KEYSTATE & KEY_UP) == 0)
		{
			d.y-=s;
		}
		if ((KEYSTATE & KEY_DOWN) == 0)
		{
			d.y+=s;
		}
		if ((KEYSTATE & KEY_LEFT) == 0)
		{
			//d.x-=s;
			player->turn(  DEG2RAD(10.0f) );
		}
		if ((KEYSTATE & KEY_RIGHT) == 0)
		{
			//d.x+=s;
			player->turn( -DEG2RAD(10.0f) );
		}

		player->move(d);
}

int main()
{
	DISPLAYCONTROL = MODE4 | BG2;

	raycaster = new Raycaster(mapS, map, mapX, mapY, fov, WIDTH, HEIGHT);

	int next_palette_index = 0;

	int black = M4_add_color(0,0,0, next_palette_index);
	int white = M4_add_color(31,31,31, next_palette_index);
	int dark_white = M4_add_color(26,26,26, next_palette_index);
	int green = M4_add_color(0,31,0, next_palette_index);
	int dark_green = M4_add_color(0,20,0, next_palette_index);
	int red = M4_add_color(31,0,0, next_palette_index);
	int dark_red = M4_add_color(20,0,0, next_palette_index);

	unsigned volatile short* current_buffer = FRONT_BUFFER;

	asm_clear_screen_m4(FRONT_BUFFER, black);
	asm_clear_screen_m4(BACK_BUFFER, black);

	int pX = 20, pY = 10;

	while(1)
	{
		asm_clear_screen_m4(current_buffer, black);
		raycaster->scanEnv(current_buffer, player->position, player->angle, fov);
		process_input(player);

		vblank();

		current_buffer = swap_buffer(current_buffer);
	}

}
