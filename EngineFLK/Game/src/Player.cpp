#include "Player.h"

Player::Player()
{
	posX = 0;
	posY = 0;
	conPosX = 0.0f;
	conPosY = 0.0f;
}

Player::Player(Shader& shader) : Sprite(shader)
{
	posX = 1;
	posY = 1;
	conPosX = 0.0f;
	conPosY = 0.0f;
}

Player::~Player()
{

}

void Player::ConvertCoord()
{

	if (posX == 0) conPosX = -0.5f;
	if (posX == 1) conPosX = 0.0f;
	if (posX == 2) conPosX = 0.5f;
	if (posY == 0) conPosY = -0.5f;
	if (posY == 1) conPosY = 0.0f;
	if (posY == 2) conPosY = 0.5f;

	transform.SetPosition(conPosX, conPosY, 0.0f);
}

//void Player::Draw()
//{
//
//}
