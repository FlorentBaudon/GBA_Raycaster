#pragma once
class Player
{
	/**** Members ****/
	public :
		//Position of the player on map
		gba::vec2 position;
		// direction where the player looking
		gba::vec2 forward;
		// right direction of the player
		gba::vec2 right;
		// angle in RADIAN 
		float angle;

		float speed;

	private : 
		gba::vec2 worldForward;
		gba::vec2 worldRight;


	/**** Functions ****/
	public:
		Player(gba::vec2 position, gba::vec2 worldForward, gba::vec2 worldRight, float angle);

		void turn(float angle);
		void move(gba::vec2 direction);
	
	private :
		void refreshPlayerDatas();

};

