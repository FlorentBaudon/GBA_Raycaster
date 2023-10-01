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
		void scanEnv(volatile uint16* buffer, const m_gba::vec2 pos, const float angle, const float fov);
	private :
		int checkCellValue(m_gba::vec2 p);
		m_gba::vec2 findHorizontalIntersect(m_gba::vec2 pos, float angle);
		m_gba::vec2 findVerticalIntersect(m_gba::vec2 pos, float angle);
		m_gba::vec2 drawRaycast(m_gba::vec2 pos, float angle, bool bDebug = false);
};

