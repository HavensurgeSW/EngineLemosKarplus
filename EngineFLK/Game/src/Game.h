#pragma once
#include "BaseGame.h"

#include "Shape.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Tilemap.h"

class Game : public BaseGame
{
private:
	AnimatedSprite* rock;
	Shape* shape;
	Sprite* enano;
	Sprite* illuminati;
	Tilemap* tilemap;

public:
	void Init() override;
	void Update() override;
	void DeInit() override;
};
