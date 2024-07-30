#ifndef TILE_H
#define TILE_H

#include "Sprite.h"



class FLK_API Tile : public Sprite
{
private:
	unsigned int id;
	bool isWalkable;

public:
	Tile();
	Tile(Shader& shader, bool initalize = true);
	~Tile();

	void SetId(unsigned int id);
	unsigned int GetId() const;


	void SetIsWalkable(bool isWalkable);
	bool GetIsWalkable() const;

	void Draw();
};

#endif
