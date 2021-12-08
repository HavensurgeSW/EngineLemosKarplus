#include "Tilemap.h"

#include "Tile.h"

#include "xml_lib/tinyxml2.h"
#include <iostream>

Tilemap::Tilemap() {}

Tilemap::~Tilemap() {}

const Tile& Tilemap::tile(unsigned int uiId) 
{
	Tile* NoTile = nullptr;

	for (int i = 0; i < tiles.size(); i++) {
		if (uiId == tiles[i].GetId()) {
			return tiles[i];
		}
	}

	return *NoTile;
}

void Tilemap::SetMapTileId(int layer, unsigned int uiCol, unsigned int uiRow, unsigned int uiId)
{
	_tileMapGrid[layer][uiCol][uiRow] = tile(uiId);
}

void Tilemap::SetTile(const Tile& rkTile) 
{
	tiles.push_back(rkTile);
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
	for (int i = 0; i < _height; i++) {
		tileMap[i] = new Tile[_width];
	}
	_tileMapGrid.push_back(tileMap);
}

void Tilemap::SetTexture(const Texture& rkTexture) 
{
	_texture = rkTexture;
}

void Tilemap::Draw() 
{
	//rkRenderer.setCurrentTexture(_texture);

	float mapWidth = -(_width * _tileWidth) / 2;
	float mapHeight = (_height * _tileHeight) / 2;

	for (int i = 0; i < _tileMapGrid.size(); i++) {
		for (int y = 0; y < _height; y++) {
			for (int x = 0; x < _width; x++) {
				if (_tileMapGrid[i][y][x].GetId() != NULL) {
					_tileMapGrid[i][y][x].transform.SetPosition({ mapWidth + (_tileWidth * x), mapHeight - (_tileHeight * y) });
					_tileMapGrid[i][y][x].Draw();
				}
			}
		}
	}

}

bool Tilemap::ImportTileMap(std::string filePath) 
{
	tinyxml2::XMLDocument doc; //guarda el documento
	tinyxml2::XMLError errorHandler; //guarda el resultado de las funciones

	errorHandler = doc.LoadFile(filePath.c_str()); //carga el archivo XML
	if (errorHandler == tinyxml2::XML_ERROR_FILE_NOT_FOUND || errorHandler == tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED) return false;

	// Loading Map element and save Map width, heigth in tiles and width, heigth of Tiles in pixels
	tinyxml2::XMLElement* mapNode = doc.FirstChildElement("map");
	if (mapNode == nullptr)
		return false;
	SetDimensions(mapNode->FloatAttribute("width"), mapNode->FloatAttribute("height"));				// Get width and heigth for
	SetTileDimensions(mapNode->FloatAttribute("tilewidth"), mapNode->FloatAttribute("tileheight")); // the map and the tiles

	// Loading Tilset element
	tinyxml2::XMLElement* pTileset = mapNode->FirstChildElement("tileset");
	if (pTileset == NULL)
		return false;

	int tileCount = pTileset->IntAttribute("tilecount"); // Number of Tiles in the Tileset
	int columns = pTileset->IntAttribute("columns");  // Columns of Tiles in the Tileset
	int rows = tileCount / columns;

	_imagePath = "Assets/";																//
	_imagePath += pTileset->FirstChildElement("image")->Attribute("source");			// Loading Textures
	// SetTexture(rkRenderer.loadTexture(_imagePath.c_str(), D3DCOLOR_XRGB(255, 255, 255))); //

	// Save the Tiles in the TileMap
	_imageWidth = pTileset->FirstChildElement("image")->IntAttribute("width");
	_imageHeight = pTileset->FirstChildElement("image")->IntAttribute("height");
	float tileX = 0.0f, tileY = 0.0f;
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
			SetTile(newTile);
			_id++;
		}

		tileX = 0;
		tileY += _tileHeight;
	}

	tinyxml2::XMLElement* pTile = pTileset->FirstChildElement("tile");

	while (pTile) {
		unsigned int id = pTile->IntAttribute("id");
		tinyxml2::XMLElement* pProperty = pTile->FirstChildElement("properties")->FirstChildElement("property");
		std::string propertyName = pProperty->Attribute("value");
		//if (propertyName == "false")
		//	tiles[id].walkability(false);
		//else
		//	tiles[id].walkability(true);

		pTile = pTile->NextSiblingElement("tile");
	}

	// Loading Layer element
	tinyxml2::XMLElement* pLayer = mapNode->FirstChildElement("layer");
	if (pLayer == NULL)
		return false;

	int layerCount = 0;
	while (pLayer) {
		// Loading Data element
		tinyxml2::XMLElement* pData = pLayer->FirstChildElement("data");
		if (pData == NULL)
			return false;

		if (layerCount > 0) {
			Tile** tileMap;
			tileMap = new Tile * [_height];
			for (int i = 0; i < _height; i++) {
				tileMap[i] = new Tile[_width];
			}
			_tileMapGrid.push_back(tileMap);
		}

		while (pData) {
			std::vector<int> tileGids;
			for (tinyxml2::XMLElement* pTile = pData->FirstChildElement("tile");
				pTile != NULL;
				pTile = pTile->NextSiblingElement("tile"))
			{
				unsigned int gid = std::atoi(pTile->Attribute("gid")); // tile's id is saved
				tileGids.push_back(gid);
			}

			int gid = 0;
			for (int y = 0; y < _height; y++) {
				for (int x = 0; x < _width; x++) {
					if (tileGids[gid] != 0)
						SetMapTileId(layerCount, y, x, tileGids[gid]);
					gid++;
				}
			}

			pData = pData->NextSiblingElement("data");
		}
		layerCount++;
		pLayer = pLayer->NextSiblingElement("layer");
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