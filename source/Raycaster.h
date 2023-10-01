#pragma once
class Raycaster
{
	/**** Members ****/
	public :
		int cellSize;
		int* map;
		int mapSizeX;
		int mapSizeY;
		int xResolution;
		int yResolution;

	/**** Functions ****/
	public :
		Raycaster(int cellSize, int* map, int mapSizeX, int mapSizeY, float fov, int xResolution, int yResolution);
		void scanEnv(volatile uint16* buffer, const gba::vec2 pos, const float angle, const float fov);
	private :
		int checkCellValue(gba::vec2 p);
		gba::vec2 findHorizontalIntersect(gba::vec2 pos, float angle);
		gba::vec2 findVerticalIntersect(gba::vec2 pos, float angle);
		gba::vec2 drawRaycast(gba::vec2 pos, float angle, bool bDebug = false);
};

