#ifndef TILE_H
#define TILE_H

#include "Sprite.h"

class Vector2;

class Tile : public Sprite
{
private:
	unsigned int id;
	bool isWalkable;

public:
	Tile();
	~Tile();

	bool GetIsWalkable() const;
	void SetIsWalkable(bool isWalkable);

	void SetId(unsigned int id);
	unsigned int GetId() const;

	void SetTextureCoordinates(Vector2 topRight, Vector2 bottomRight, Vector2 bottomLeft, Vector2 topLeft);
};

#endif
