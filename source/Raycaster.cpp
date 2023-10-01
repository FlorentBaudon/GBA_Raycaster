#include "MathTools.h"
#include "Raycaster.h"
#include "GBADrawTools.h"
#include "GBA_VAR.h"

Raycaster::Raycaster(int cellSize, int* map, int mapSizeX, int mapSizeY, float fov, int xResolution, int yResolution) 
{
	this->cellSize = cellSize; 
	this->map = map; 
	this->mapSizeX = mapSizeX; 
	this->mapSizeY = mapSizeY; 
	this->xResolution = xResolution;
	this->yResolution = yResolution;
}

int Raycaster::checkCellValue(m_gba::vec2 p)
{
	if (p.x > mapSizeX * cellSize || p.y > mapSizeY * cellSize || p.x < 0 || p.y < 0)
	{
		return -1;
	}

	m_gba::vec2 t_p = m_gba::vec2(0, 0); //truncate position
	t_p.x = int(p.x / cellSize);
	t_p.y = int(p.y / cellSize);

	int tabPos = t_p.x + (mapSizeX * t_p.y);

	int cell = map[tabPos];

	return cell;
}

m_gba::vec2 Raycaster::findHorizontalIntersect(m_gba::vec2 pos, float angle)
{
	m_gba::vec2 p = m_gba::vec2(0, 0);
	m_gba::vec2 delta = m_gba::vec2(0, 0);

	bool bIntersect = false;

	if (m_gba::sin(angle) > 0.001f)
	{
		p.y = int(pos.y / cellSize) * cellSize - pos.y - 0.0001f;
		p.x = m_gba::tan(angle + PI / 2) * p.y;
		p = pos + p;

		delta.x = cellSize / m_gba::tan(angle);
		delta.y = -cellSize;
	}
	else if (m_gba::sin(angle) < -0.001f)
	{
		p.y = int(pos.y / cellSize) * cellSize - pos.y + cellSize;
		p.x = m_gba::tan(angle + PI / 2) * p.y;
		p = pos + p;

		delta.x = cellSize / m_gba::tan(-angle);
		delta.y = +cellSize;
	}
	else {
		return m_gba::vec2(100000, 100000);
	}


	bIntersect = (checkCellValue(p) != 0);

	while (!bIntersect)
	{
		p = p + delta;
		bIntersect = (checkCellValue(p) != 0);
	}

	return p;

}

m_gba::vec2 Raycaster::findVerticalIntersect(m_gba::vec2 pos, float angle)
{

	m_gba::vec2 p = m_gba::vec2(0, 0);
	m_gba::vec2 d = m_gba::vec2(0, 0);

	bool bIntersect = false;

	if (m_gba::cos(angle) < -0.001f)
	{
		p.x = int(pos.x / cellSize) * cellSize - pos.x - 0.0001f;
		p.y = -m_gba::tan(angle) * p.x;
		p = pos + p;

		d.x = -cellSize;
		d.y = cellSize * m_gba::tan(angle);

	}
	else if (m_gba::cos(angle) > 0.001f)
	{
		p.x = int(pos.x / cellSize) * 64 - pos.x + cellSize;
		p.y = -m_gba::tan(angle) * p.x;
		p = pos + p;

		d.x = cellSize;
		d.y = cellSize * m_gba::tan(-angle);
	}
	else
	{
		return m_gba::vec2(100000, 100000); // return infinite point 
	}

	bIntersect = (checkCellValue(p) != 0);

	while (!bIntersect)
	{
		p = p + d;
		bIntersect = (checkCellValue(p) != 0);
	}

	return p;
}


m_gba::vec2 Raycaster::drawRaycast(m_gba::vec2 pos, float angle, bool bDebug)
{
	m_gba::vec2 pH = this->findHorizontalIntersect(pos, angle);
	m_gba::vec2 pV = this->findVerticalIntersect(pos, angle);

	float dH = m_gba::length(pH - pos);
	float dV = m_gba::length(pV - pos);

	return (dH < dV) ? pH : pV;
}

void Raycaster::scanEnv(unsigned volatile short* buffer, const m_gba::vec2 pos, const float angle, const float fov)
{
	const float r_angle = angle + fov / 2;

	int resX = this->xResolution, resY = this->yResolution;
	const float dScreen = (resX / 2) / m_gba::tan(fov / 2);
	int hMur = 64;
	float angleStep = fov / resX;

	for (int i = 0; i < resX; i++)
	{
		float a = r_angle - angleStep * i;


		/****** Launch raycast, je n'appelle pas la fonction car j'ai besoin des infos de dism_gba::tance pour le shading (savoir si c'est un intersect horizontale ou verticale ****/
		m_gba::vec2 pH = this->findHorizontalIntersect(pos, a);
		m_gba::vec2 pV = this->findVerticalIntersect(pos, a);

		float dH = length(pH - pos);
		float dV = length(pV - pos);


		m_gba::vec2 p = (dH < dV) ? pH : pV;
		/********************************************************************************************************/

		float d = length(p - pos);
		d *= m_gba::cos(a - angle);// * m_gba::cos (player_angle - a) to correct dism_gba::tance to avoid fishey effect
		int r = this->checkCellValue(p);


		if (true)
		{
			float hp = dScreen * (hMur / d);

			m_gba::vec2 start(i, resY / 2 - (hp / 2));
			m_gba::vec2 end(i, resY / 2 + (hp / 2));

			int color =0;

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
				// draw_vert_line(buffer, start.x, start.y, end.x, end.y, color);
				ASM_draw_vert_line(buffer, color, start.x, start.y, end.y);
			}
		}


	}
}