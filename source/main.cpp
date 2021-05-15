#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include "GBA_VAR.h"
#include "GBADrawTools.h"
#include "Player.h"
#include "Raycaster.h"

#define PI 3.1415f
#define DEG2RAD(x) x*(3.1415f/180.f)
#define RAD2DEG(x) x*(180.f/3.1415f)

using namespace glm;

vec2 world_forward = vec2(1,0);
vec2 world_right = vec2(0, 1);
float fov = DEG2RAD(60.f);

/********* Player **********/
Player* player = new Player(vec2(288, 70), world_forward, world_right, radians(-90.f));

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


volatile short* swap_buffer(volatile short* buffer_to_show)
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
			d.x-=s;
			// player->turn(  radians(10.0f) );
		}
		if ((KEYSTATE & KEY_RIGHT) == 0)
		{
			d.x+=s;
			// player->turn( -radians(10.0f) );
		}

		player->move(d);
}

int main()
{
	DISPLAYCONTROL = MODE4 | BG2;

	raycaster = new Raycaster(mapS, map, mapX, mapY, fov, WIDTH, HEIGHT);

	int next_palette_index = 0;

	int black = add_color(0,0,0, next_palette_index);
	int white = add_color(31,31,31, next_palette_index);
	int dark_white = add_color(26,26,26, next_palette_index);
	int green = add_color(0,31,0, next_palette_index);
	int dark_green = add_color(0,20,0, next_palette_index);
	int red = add_color(31,0,0, next_palette_index);
	int dark_red = add_color(20,0,0, next_palette_index);

	volatile short* current_buffer = FRONT_BUFFER;

	clear_screen(FRONT_BUFFER, black);
	clear_screen(BACK_BUFFER, black);

	int pX = 20, pY = 10;

	while(1)
	{
		// draw_rect(current_buffer, player->position.x-1,player->position.y-1,12,12, black);

		raycaster->scanEnv(current_buffer, player->position, player->angle, fov);
		process_input(player);

		// draw_rect(current_buffer, player->position.x,player->position.y,10,10, green);

		vblank();

		current_buffer = swap_buffer(current_buffer);
	}

}
