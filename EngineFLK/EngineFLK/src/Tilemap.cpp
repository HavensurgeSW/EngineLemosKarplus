#include "Tilemap.h"
#include "Tile.h"
#include "xml_lib/tinyxml2.h"	
#include <sstream>

Tilemap::Tilemap(Vector2 dimensions, Shader shader, std::string imagePath) 
{
	this->dimensions = dimensions;
	this->shader = shader;
	this->imagePath = imagePath;
}

Tilemap::~Tilemap() 
{
	if (!grid.empty()) 
	{
		for (int l = 0; l < grid.size(); l++) 
		{
			for (int y = 0; y < grid[l].size(); y++) 
			{
				for (int x = 0; x < grid[l][y].size(); x++) 
				{
					grid[l][y][x] = 0;
				}
			}
		}
		grid.clear();
	}

	if (!tiles.empty()) {
		for (int i = 0; i < tiles.size(); i++) {
			if (tiles[i] != NULL) {
				delete tiles[i];
				tiles[i] == NULL;
			}
		}
		tiles.clear();
	}
}

void Tilemap::SetImagePath(std::string imagepath) 
{
	this->imagePath = imagepath;
}

void Tilemap::LoadMap(std::string path) 
{
	tinyxml2::XMLDocument map;
	map.LoadFile(path.c_str());
	tinyxml2::XMLElement* mapElements = map.FirstChildElement("map");

	if (mapElements == NULL) 
	{
		std::cout << "Error loading tilemap" << std::endl;
		return;
	}

	int width = mapElements->IntAttribute("width");
	int height = mapElements->IntAttribute("height");
	tileWidth = mapElements->IntAttribute("tilewidth");
	tileHeight = mapElements->IntAttribute("tileheight");

	int layers = 0;
	std::vector<tinyxml2::XMLElement*>layerElement;
	for (tinyxml2::XMLElement* child = mapElements->FirstChildElement(); child; child = child->NextSiblingElement()) 
	{
		std::string name = child->Name();
		std::string layer = "layer";
		if (child != NULL && name == layer) 
		{
			layers++;
			layerElement.push_back(child);
		}
	}

	std::cout << layers << std::endl;
	grid.resize(layers);
	for (int l = 0; l < grid.size(); l++) 
	{
		tinyxml2::XMLText* dataElement = layerElement[l]->FirstChildElement("data")->FirstChild()->ToText();
		if (dataElement == NULL) 
		{
			std::cout << "Error loading tilemap" << std::endl;
			return;
		}

		std::string mapGrid;
		mapGrid = dataElement->Value();
		std::stringstream ss(mapGrid);
		grid[l].resize(height);
		for (int y = 0; y < width; y++) 
		{
			grid[l][y].resize(width);

			for (int x = 0; x < height; x++) 
			{
				std::string value;
				std::getline(ss, value, ',');

				if (!ss.good()) 
				{
					break;
				}

				int val;
				if (std::stringstream(value) >> val) 
				{
					grid[l][y][x] = val;
				}

				tilesAmmount++;
			}
		}
	}
	LoadTilesFromMap();
}


void Tilemap::LoadTilesFromMap() 
{
	//_texture->SetPath(imagePath);
	//_texture->LoadImage(imageWidth, imageHeight, true);
	float xPos = 0;
	float yPos = 720;

	for (int l = 0; l < grid.size(); l++) 
	{
		for (int y = 0; y < grid[l].size(); y++) 
		{
			for (int x = 0; x < grid[l][y].size(); x++) 
			{
				Tile* newTile = new Tile(grid[l][y][x], true, shader);
				//newTile->SetPath(imagePath);
				newTile->Init();
				newTile->transform.Translate({ xPos, yPos, l - 0.5f });
				newTile->transform.SetScale({ tileWidth, tileHeight, 1 });

				int id = newTile->GetID() <= 0 && l > 0 ? grid[l - 1][y][x] - 1 : newTile->GetID() - 1;
				newTile->SetUVs(GetTileFromID(id));

				tiles.push_back(newTile);
				xPos += newTile->transform.GetScale().x + tileWidth;
			}

			yPos -= tileHeight + tileHeight;
			xPos = 0;
		}
	}
}

Vector4 Tilemap::GetTileFromID(unsigned int id)
{
	int xTile = id % static_cast<int>(dimensions.x);
	int yTile = id / static_cast<int>(dimensions.x);
	yTile = imageHeight - yTile - 1;

	Vector4 uv;
	uv.x = xTile / dimensions.x;
	uv.y = yTile / dimensions.y;
	uv.z = 1.0f / dimensions.x; 
	uv.w = 1.0f / dimensions.y; 

	return uv;
}

void Tilemap::Draw()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		if (tiles[i] != NULL)
		{
			tiles[i]->Draw();
		}
	}
}