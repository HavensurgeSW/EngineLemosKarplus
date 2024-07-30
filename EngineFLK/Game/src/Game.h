#pragma once
#include "BaseGame.h"

#include "Shape.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "spritesheet.h"
#include "Tilemap.h"


struct tilePlayer {
	Sprite* tex;
	Vector2 pos;
};

class Game : public BaseGame
{
private:
	AnimatedSprite* rock;
	Shape* shape;
	Sprite* enano;
	Sprite* illuminati;
	Sprite* player;
	tilePlayer p1;

	Tilemap* tilemap;

	bool showTilemap;

public:
	void Init() override;
	void Update() override;
	void DeInit() override;
};
