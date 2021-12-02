#pragma once
#include "BaseGame.h"

#include "Shape.h"
#include "Sprite.h"

class Game : public BaseGame
{
private:
	Shape* shape;
	Sprite* rock;
	Sprite* enano;
	Sprite* illuminati;


public:
	void Init() override;
	void Update() override;
	void DeInit() override;
};
