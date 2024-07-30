#ifndef TILEMAP_H
#define TILEMAP_H

#include "Exports.h"

#include "Tile.h"
#include "spritesheet.h"

#include <iostream>
#include <vector>
class FLK_API Tilemap
{
private:
	spritesheet* basesheet;
	Shader shaderPath;
	Tile*** map;
	Vector2 mapDim;

public:
	Tilemap();
	Tilemap(const std::string& texPath, Vector2 sheetPXSize, Vector2 tilePXSize, Vector2 mapDimensions, Shader shader);
	~Tilemap();

	Tile* getTile(int x, int y);
	Tile* getTile(Vector2 tileCoord);
	spritesheet* getSheet();

	void TurnUnwalkableByID(int id);


	void Draw();
};

#endif

