#ifndef TILEMAP_H
#define TILEMAP_H

#include "Texture.h"
#include <vector>
#include <string>
#include "Vector2.h"
#include "Sprite.h"

struct FLK_API Tile 
{
	unsigned int id;
	Vector2 pos;
	Vector2 convertedPos;

	Sprite* sprite;
};

class FLK_API Tilemap 
{
private:
	static const int maxTLX = 2;
	static const int maxTLY = 2;
	static const int tileSize = 80;

public:
	Tile board[maxTLY][maxTLX];
	Tilemap();
	~Tilemap();
	void initMap();
	Vector2 getPos(int x, int y);
	Vector2 getConvertedPos(int x, int y);
	
};
#endif
