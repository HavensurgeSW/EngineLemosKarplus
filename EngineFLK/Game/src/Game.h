#pragma once
#include "BaseGame.h"

#include "Shape.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Tilemap.h"
#include "Player.h"

class Game : public BaseGame
{
private:
	Player* player;
	AnimatedSprite* rock;
	Shape* shape;
	Sprite* enano;
	Sprite* illuminati;
	Tilemap* tilemap;

	bool showTilemap;

public:
	void Init() override;
	void Update() override;
	void DeInit() override;
};
