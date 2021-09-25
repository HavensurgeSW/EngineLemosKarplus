#pragma once
#include "Exports.h"
#include "Animation.h"
#include "Entity2D.h"

class FLK_API Sprite : public Entity2D
{
private:
	Animation animation;

public:
	Sprite();
	~Sprite();
};

