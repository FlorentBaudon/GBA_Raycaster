#pragma once
class Raycaster
{
	/**** Members ****/
	public :
		uint8 cellSize;
		uint8* map;
		uint16 mapSizeX;
		uint16 mapSizeY;
		uint8 xResolution;
		uint8 yResolution;
		float fov;

	/**** Functions ****/
	public :
		Raycaster(uint8 cellSize, uint8* map, uint16 mapSizeX, uint16 mapSizeY, float fov, uint8 xResolution, uint8 yResolution);
		void scanEnv(unsigned volatile short* buffer, const gba::vec2 pos, const float angle);
	private :
		int8 checkCellValue(gba::vec2 p);
		gba::vec2 findHorizontalIntersect(gba::vec2 pos, float angle);
		gba::vec2 findVerticalIntersect(gba::vec2 pos, float angle);
		gba::vec2 drawRaycast(gba::vec2 pos, float angle, bool bDebug = false);
};

