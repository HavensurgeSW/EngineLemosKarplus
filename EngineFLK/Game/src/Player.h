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


	//void Draw() override;
};

#endif