#ifndef TILEMAP_H
#define TILEMAP_H

#include "Texture.h"
#include <vector>
#include <string>

class Tile;

class FLK_API Tilemap 
{
private:
	//std::vector<Tile> tiles;
	//std::vector<Tile**> _tileMapGrid;

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
	Tilemap(int tileCount, int columns, float width, float height);
	~Tilemap();

	bool ImportTileMap(std::string filePath, int tileCount, int columns, float width, float height);
	
	void AddTile(const Tile& tile);
	//void SetMapTileId(int layer, unsigned int uiCol, unsigned int uiRow, unsigned int uiId);
	//const Tile& GetTile(unsigned int uiId);

	void SetDimensions(float width, float heigth);
	void SetTileDimensions(float tileWidth, float tileHeigth);

	void SetTexture(const Texture& texture);
	void SetTexture(const std::string& path);
	void Draw();

	//void checkCollision(Entity2D& object);
};
#endif
