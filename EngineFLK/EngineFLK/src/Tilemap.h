#ifndef TILEMAP_H
#define TILEMAP_H

#include "Exports.h"

#include "Tile.h"
#include "spritesheet.h"

#include <iostream>
#include <vector>
class FLK_API Tilemap : Entity2D
{
private:
	spritesheet* basesheet;
	Shader shaderPath;
	Tile*** map;
	Vector2 mapDim;
	int mapSlots;


public:
	Tilemap();
	Tilemap(const std::string& texPath, Vector2 sheetPXSize, Vector2 tilePXSize, Vector2 mapDimensions, Shader shader);
	~Tilemap();

	void GenerateMapFromVec(const std::vector<int>& vec);

	Tile* getTile(int x, int y);
	Tile* getTile(Vector2 tileCoord);
	spritesheet* getSheet();
	Vector2 GetMapDim();

	void CheckTileCollisions(Entity2D* actor);
	bool CollisionWithAdjTile(Entity2D* actor, Vector2 tile);

	void TurnUnwalkableByID(int id);

	


	void Draw();
};

#endif

