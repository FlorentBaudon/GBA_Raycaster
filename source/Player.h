#pragma once
class Player
{
	/**** Members ****/
	public :
		//Position of the player on map
		m_gba::vec2 position;
		// direction where the player looking
		m_gba::vec2 forward;
		// right direction of the player
		m_gba::vec2 right;
		// angle in RADIAN 
		float angle;

		float speed;

	private : 
		m_gba::vec2 worldForward;
		m_gba::vec2 worldRight;


	/**** Functions ****/
	public:
		Player(m_gba::vec2 position, m_gba::vec2 worldForward, m_gba::vec2 worldRight, float angle);

		void turn(float angle);
		void move(m_gba::vec2 direction);
	
	private :
		void refreshPlayerDatas();

};

