#include "Player.h"

Player::Player()
{
	posX = 0;
	posY = 0;
}

Player::Player(Shader& shader) : Sprite(shader)
{
	posX = 1;
	posY = 1;
}

Player::~Player()
{

}

//void Player::Draw()
//{
//
//}
