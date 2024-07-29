#pragma once
#include "BaseGame.h"

#include "Shape.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "spritesheet.h"
#include "Tilemap.h"


class Game : public BaseGame
{
private:
	AnimatedSprite* rock;
	Shape* shape;
	Sprite* enano;
	Sprite* illuminati;
	Sprite* player;
	
	spritesheet* dungeonSheet;
	Tile* boxy;
	Tilemap* tilemap;

	bool showTilemap;

public:
	void Init() override;
	void Update() override;
	void DeInit() override;
};
