#ifndef TILE_H
#define TILE_H

#include "sprite.h"

class FLK_API Tile : public Sprite
{
private:
	unsigned int id;
	bool isWalkable;

public:
	Tile();
	Tile(unsigned int id, bool isWalkable, Shader& shader);
	~Tile();
	void SetIsWalkable(bool value);
	bool GetIsWalkable();
	unsigned int GetID();
	void SetID(unsigned int value);
};

#endif // !TILE_H
