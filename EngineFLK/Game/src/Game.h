#pragma once
#include "BaseGame.h"

#include "Shape.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "spritesheet.h"
#include "Tilemap.h"
#include "Utils.h"


struct tilePlayer {
	Sprite* tex;
	Vector2 pos;
	Vector2 bounds;
};

class Game : public BaseGame
{
private:
	AnimatedSprite* rock;
	Shape* shape;
	Sprite* enano;
	Sprite* illuminati;

	Tilemap* tilemap;
	tilePlayer p1;

	bool showTilemap;

public:
	void Init() override;
	void Update() override;
	void DeInit() override;
};
