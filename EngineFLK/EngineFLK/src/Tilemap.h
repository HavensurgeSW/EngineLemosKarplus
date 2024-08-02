#ifndef TILEMAP_H
#define TILEMAP_H

#include "Exports.h"

#include "Tile.h"
#include "spritesheet.h"
#include "CollisionManager.h"

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
	float tileScale;


	CollisionManager* collisionManager;


public:
	Tilemap();
	Tilemap(const std::string& texPath, Vector2 sheetPXSize, Vector2 tilePXSize, float transformScale, Vector2 mapDimensions, Shader shader);
	~Tilemap();

	void SetCollisionManager(CollisionManager* cm);

	void GenerateMapFromVec(const std::vector<int>& vec);

	Tile* getTile(int x, int y);
	Tile* getTile(Vector2 tileCoord);
	spritesheet* getSheet();
	Vector2 GetMapDim();

	bool CheckTileCollisions(Entity2D* actor);
	bool CollisionWithAdjTile(Entity2D* actor, Vector2 tile);

	//painting functions
	void TurnUnwalkableByID(int id);
	void MakeOuterWallUnwalkable();
	void MakeOuterWallWithID(int id);


	void Draw();
};

#endif

