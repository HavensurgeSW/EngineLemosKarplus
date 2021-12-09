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
	Sprite* sprite;
	Vector2 pos;
	Vector2 convertedPos;

	bool isWalkable;
};

class FLK_API Tilemap
{
private:
	static const int maxTLX = 3;
	static const int maxTLY = 3;
	static const int tileSize = 80;

	int convertedPosX;
	int convertedPosY;
	Shader shader;
	std::vector<Tile> tiles;

public:
	Tile board[maxTLY][maxTLX];
	Tilemap();
	~Tilemap();
	void initMap();
	Vector2 getPos(int x, int y);
	Vector2 getConvertedPos(int x, int y);
	Tile GetTile(int x, int y) const;
	void SetTileID(int x, int y, int id);
	void Draw();

	//void CheckCollision(Entity2D& object);
};
#endif
