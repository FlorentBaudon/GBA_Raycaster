#include "MathTools.h"

#include "Player.h"

using namespace gba;

Player::Player(vec2 position, vec2 worldForward, vec2 worldRight, float angle) 
{
	this->position = position;
	this->worldForward = worldForward;
	this->worldRight = worldRight;
	this->forward = worldForward;
	this->right = worldRight;
	this->angle = angle;

	this->refreshPlayerDatas();
}

void Player::turn(float angle) 
{
	this->angle += angle;
	this->refreshPlayerDatas();
	
}

void Player::move(vec2 direction) 
{
	if (length(direction) > 0)
	{
		vec2 d = rotateVectorRad(direction, this->angle);
		this->position = this->position + d;
	}
}

void Player::refreshPlayerDatas()
{
	this->forward = rotateVectorRad(this->worldForward, this->angle);
	this->right = rotateVectorRad(this->worldRight, this->angle);
}
