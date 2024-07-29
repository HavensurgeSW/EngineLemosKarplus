#pragma once
#include "BaseGame.h"

#include "Shape.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Tilemap.h"
#include "spritesheet.h"


class Game : public BaseGame
{
private:
	AnimatedSprite* rock;
	Shape* shape;
	Tile* boxy;
	Sprite* enano;
	Sprite* illuminati;
	Sprite* player;
	//Tilemap* tilemap;
	spritesheet* dungeonSheet;

	bool showTilemap;

public:
	void Init() override;
	void Update() override;
	void DeInit() override;
};
