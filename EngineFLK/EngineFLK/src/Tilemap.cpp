#include "Tilemap.h"

#include "Tile.h"

#include <iostream>

Tilemap::Tilemap() {}

Tilemap::Tilemap(int tileCount, int columns, float width, float height)
{
	SetDimensions(width, height);                 // Get width and heigth for
	SetTileDimensions(_tileWidth, _tileHeight);	  // the map and the tiles
}

Tilemap::~Tilemap() {}

//const Tile& Tilemap::GetTile(unsigned int uiId)
//{
//	Tile* nullTile = nullptr;
//	//
//	//for (int i = 0; i < tiles.size(); i++) 
//	//{
//	//	if (uiId == tiles[i].GetId()) 
//	//	{
//	//		return tiles[i];
//	//	}
//	//}
//	//
//	return *nullTile;
//}

//void Tilemap::SetMapTileId(int layer, unsigned int uiCol, unsigned int uiRow, unsigned int uiId)
//{
//	_tileMapGrid[layer][uiCol][uiRow] = GetTile(uiId);
//}

void Tilemap::AddTile(const Tile& tile)
{
	//tiles.push_back(tile);
}

void Tilemap::SetTileDimensions(float tileWidth, float tileHeight) 
{
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
}

void Tilemap::SetDimensions(float width, float height) 
{
	_width = width;
	_height = height;

	//creo la grilla bidimensional para guardar la posicion de cada tile igual que en el editor
	Tile** tileMap;
	tileMap = new Tile * [_height];
	for (int i = 0; i < _height; i++) 
	{
		tileMap[i] = new Tile[_width];
	}
	//_tileMapGrid.push_back(tileMap);
}

void Tilemap::SetTexture(const Texture& texture) 
{
	_texture = texture;
}

void Tilemap::SetTexture(const std::string& path)
{
	_texture.LoadTexture(path);
}

void Tilemap::Draw() 
{
	float mapWidth = -(_width * _tileWidth) / 2;
	float mapHeight = (_height * _tileHeight) / 2;

	//for (int i = 0; i < _tileMapGrid.size(); i++) 
	//{
	//	for (int y = 0; y < _height; y++) 
	//	{
	//		for (int x = 0; x < _width; x++) 
	//		{
	//			if (_tileMapGrid[i][y][x].GetId() != NULL) 
	//			{
	//				_tileMapGrid[i][y][x].transform.SetPosition({ mapWidth + (_tileWidth * x), mapHeight - (_tileHeight * y) });
	//				_tileMapGrid[i][y][x].Draw();
	//			}
	//		}
	//	}
	//}
}

bool Tilemap::ImportTileMap(std::string filePath, int tileCount, int columns, float width, float height)
{
	int rows = tileCount / columns;

	// Save the Tiles in the TileMap
	float tileX = 0.0f;
	float tileY = 0.0f;

	int _id = 1;
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			Tile newTile;

			newTile.SetId(_id);
			newTile.SetTexture(_texture);
			newTile.transform.SetScale({ _tileWidth, _tileHeight, 1 });

			newTile.SetTextureCoordinates({ tileX / _imageWidth, tileY / _imageHeight },
										  { (tileX + _tileWidth) / _imageWidth, tileY / _imageHeight },
										  { tileX / _imageWidth, (tileY + _tileHeight) / _imageHeight },
										  { (tileX + _tileWidth) / _imageWidth, (tileY + _tileHeight) / _imageHeight });

			tileX += _tileWidth;
			AddTile(newTile);
			_id++;
		}

		tileX = 0;
		tileY += _tileHeight;
	}
	return true;
}

/*void Tilemap::checkCollision(Entity2D& object)
{

	convertedPosX = object.posX() + (_width / 2) * _tileWidth;
	convertedPosY = object.posY() - (_height / 2) * _tileHeight;

	int left_tile = convertedPosX / _tileWidth;
	int right_tile = (convertedPosX + object.scaleX()) / _tileWidth;

	int top_tile = (convertedPosY / _tileHeight) * -1;
	int bottom_tile = ((convertedPosY - object.scaleY()) / _tileHeight) * -1; // Se resta porque el eje Y crece hacia arriba

	if (left_tile < 0)
		left_tile = 0;

	if (right_tile >= _width)
		right_tile = _width - 1;

	if (top_tile < 0)
		top_tile = 0;

	if (bottom_tile >= _height)
		bottom_tile = _height - 1;

	
	//cout << "converted X: " << convertedPosX << endl;
	//cout << "converted Y: " << convertedPosY << endl;
	//
	//cout << "left: " <<left_tile << endl;
	//cout << "right: "<<right_tile << endl;
	//cout << "top: " << top_tile << endl;
	//cout << "bottom: "<<bottom_tile << endl;
	

	for (int i = left_tile; i <= right_tile; i++) {

		for (int j = top_tile; j <= bottom_tile; j++) {

			for (int k = 0; k < _tileMapGrid.size(); k++) {
				//cout << "caminable " << "[" << k << "]" << "[" << j << "]" << "[" << i << "] : "<< _tileMapGrid[k][j][i].isWalkable() << endl; // true == 1  ; false == 0
				//cout << true << endl;
				if (!_tileMapGrid[k][j][i].isWalkable()) {

					if (_tileMapGrid[k][j][i].checkCollision(object) == CollisionHorizontalRight ||
						_tileMapGrid[k][j][i].checkCollision(object) == CollisionHorizontalLeft)
						object.returnToPreviusPosH();

					if (_tileMapGrid[k][j][i].checkCollision(object) == CollisionVerticalUp)
						object.returnToPreviusPos(object.posX(), object.previusPosY() + 0.2);

					else if (_tileMapGrid[k][j][i].checkCollision(object) == CollisionVerticalDown)
						object.returnToPreviusPos(object.posX(), object.previusPosY() - 0.2);
				}
			}
		}
	}
}*/