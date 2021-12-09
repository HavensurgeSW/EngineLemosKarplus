#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

class Shader;

class Player : public Sprite
{
private:

public:
	Player();
	Player(Shader& shader);
	~Player();

	int posX;
	int posY;

	float conPosX;
	float conPosY;

	void ConvertCoord();


	//void Draw() override;
};

#endif