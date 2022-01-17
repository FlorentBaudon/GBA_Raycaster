#include "MathTools.h"
#include "Raycaster.h"
#include "GBADrawTools.h"
#include "GBA_VAR.h"


#include <string>
extern "C" void vbaprint(const char *message);

extern "C" void asm_draw_line_m4(volatile unsigned short* buffer, unsigned char color, unsigned short x, unsigned short y, unsigned short endy) CODE_IN_IWRAM;

Raycaster::Raycaster(int cellSize, int* map, int mapSizeX, int mapSizeY, float fov, int xResolution, int yResolution) 
{
	this->cellSize = cellSize; 
	this->map = map; 
	this->mapSizeX = mapSizeX; 
	this->mapSizeY = mapSizeY; 
	this->xResolution = xResolution;
	this->yResolution = yResolution;
}

int Raycaster::checkCellValue(gba::vec2 p)
{
	if (p.x > mapSizeX * cellSize || p.y > mapSizeY * cellSize || p.x < 0 || p.y < 0)
	{
		return -1;
	}

	gba::vec2 t_p = gba::vec2(0, 0); //truncate position
	t_p.x = int(p.x / cellSize);
	t_p.y = int(p.y / cellSize);

	int tabPos = t_p.x + (mapSizeX * t_p.y);

	int cell = map[tabPos];

	return cell;
}

gba::vec2 Raycaster::findHorizontalIntersect(gba::vec2 pos, float angle)
{
	gba::vec2 p = gba::vec2(0, 0);
	gba::vec2 delta = gba::vec2(0, 0);

	bool bIntersect = false;

	if (gba::sin(angle) > 0.001f)
	{
		p.y = int(pos.y / cellSize) * cellSize - pos.y - 0.0001f;
		p.x = gba::tan(angle + PI / 2) * p.y;
		p = pos + p;

		delta.x = cellSize / gba::tan(angle);
		delta.y = -cellSize;
	}
	else if (gba::sin(angle) < -0.001f)
	{
		p.y = int(pos.y / cellSize) * cellSize - pos.y + cellSize;
		p.x = gba::tan(angle + PI / 2) * p.y;
		p = pos + p;

		delta.x = cellSize / gba::tan(-angle);
		delta.y = +cellSize;
	}
	else {
		return gba::vec2(100000, 100000);
	}


	bIntersect = (checkCellValue(p) != 0);

	while (!bIntersect)
	{
		p = p + delta;
		bIntersect = (checkCellValue(p) != 0);
	}

	return p;

}

gba::vec2 Raycaster::findVerticalIntersect(gba::vec2 pos, float angle)
{
	gba::vec2 p = gba::vec2(0, 0);
	gba::vec2 d = gba::vec2(0, 0);

	bool bIntersect = false;

	if (gba::cos(angle) < -0.001f)
	{
		p.x = int(pos.x / cellSize) * cellSize - pos.x - 0.0001f;
		p.y = -gba::tan(angle) * p.x;
		p = pos + p;

		d.x = -cellSize;
		d.y = cellSize * gba::tan(angle);

	}
	else if (gba::cos(angle) > 0.001f)
	{
		p.x = int(pos.x / cellSize) * 64 - pos.x + cellSize;
		p.y = -gba::tan(angle) * p.x;
		p = pos + p;

		d.x = cellSize;
		d.y = cellSize * gba::tan(-angle);
	}
	else
	{
		return gba::vec2(100000, 100000); // return infinite point 
	}

	bIntersect = (checkCellValue(p) != 0);

	while (!bIntersect)
	{
		p = p + d;
		bIntersect = (checkCellValue(p) != 0);
	}

	return p;
}

void Raycaster::scanEnv(unsigned volatile short* buffer, const gba::vec2 pos, const float angle, const float fov)
{
	const float r_angle = angle + fov / 2;

	const int resX = this->xResolution, resY = this->yResolution;
	const float dScreen = (resX / 2) / gba::tan(fov / 2);
	const int hMur = 64;
	const float angleStep = fov / resX;

		std::string msg = "resX : " + std::to_string(resX) + "- resY : " + std::to_string(resY) + " - r_angle : " + std::to_string(r_angle) + " - fov : " + std::to_string(fov) + "\n";
	vbaprint(msg.c_str());

	for (int i = 0; i < resX; i++)
	{
		float a = r_angle - angleStep * i;


		/****** Launch raycast, je n'appelle pas la fonction car j'ai besoin des infos de distance pour le shading (savoir si c'est un intersect horizontale ou verticale ****/
		gba::vec2 pH = this->findHorizontalIntersect(pos, a);
		gba::vec2 pV = this->findVerticalIntersect(pos, a);

		float dH = length(pH - pos);
		float dV = length(pV - pos);


		gba::vec2 p = (dH < dV) ? pH : pV;
		/********************************************************************************************************/

		float d = length(p - pos);
		d *= gba::cos(a - angle);// * gba::cos (player_angle - a) to correct distance to avoid fishey effect
		int r = this->checkCellValue(p);


			float hp = dScreen * (hMur / d);

		gba::vec2 start(i, (resY / 2) - (hp / 2));
		gba::vec2 end(i, (resY / 2) + (hp / 2));

		int color = 0;

			switch (r)
			{
			case -1:
				color = 1;
				break;
			case 0:
				color = 0;
				break;
			case 1:
				color = 1;
				break;
			case 2:
				color = 3;
				break;
			case 3:
				color = 5;
				break;
			default:
				break;
			}

			//""Lighting""
			if (dV < dH)
			{
				color += 1;
			}

			if(start.y != 0 && end.y != 0)
			{
			//  draw_vert_line(buffer, start.x, start.y, end.x, end.y, color);
				asm_draw_line_m4(buffer, color, start.x, start.y, end.y);
		}

	}
}