#ifndef TILEMAP_H
#define TILEMAP_H

#include "Texture.h"
#include <vector>
#include <string>

class Tile;

class Tilemap 
{
private:
	std::vector<Tile> tiles;
	std::vector<Tile**> _tileMapGrid;

	unsigned int _width;
	unsigned int _height;

	float _tileWidth;
	float _tileHeight;

	Texture _texture;

	float _imageWidth;
	float _imageHeight;

	float convertedPosX;
	float convertedPosY;

	std::string _imagePath;

public:
	Tilemap();
	~Tilemap();

	const Tile& tile(unsigned int uiId);
	void SetTile(const Tile& rkTile);
	void SetMapTileId(int layer, unsigned int uiCol, unsigned int uiRow, unsigned int uiId);

	void SetDimensions(float width, float heigth);
	void SetTileDimensions(float tileWidth, float tileHeigth);

	void SetTexture(const Texture& rkTexture);
	void Draw();

	bool ImportTileMap(std::string filePath);
	//void checkCollision(Entity2D& object);
};
#endif
