#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <string>
#include "Shader.h"
#include "Vector2.h"
#include "Vector4.h"

class Tile;

class FLK_API Tilemap
{
private:
	std::vector<Tile*> tiles;
	std::vector<std::vector<std::vector<int>>> grid;

	Vector2 dimensions;
	Shader shader;

	std::string imagePath;

	int imageWidth = 0;
	int imageHeight = 0;
	float tileWidth = 0;
	float tileHeight = 0;
	int tilesAmmount = 0;

	void LoadTilesFromMap();

public:
	Tilemap(Vector2 dimensions, Shader shader, std::string imagePath);
	~Tilemap();
	void SetImagePath(std::string imagepath);
	void LoadMap(std::string path);
	Vector4 GetTileFromID(unsigned int id);

	void Draw();
};




#endif // !TILEMAP_H

