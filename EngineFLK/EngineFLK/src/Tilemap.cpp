#include "Tilemap.h"


Tilemap::Tilemap(){
	basesheet = new spritesheet("", {0,0}, {0,0});
	

}

Tilemap::Tilemap(const std::string& texPath, Vector2 sheetPXSize,Vector2 TilePXSize, Vector2 mapDimensions, Shader shader) {
	basesheet = new spritesheet(texPath, sheetPXSize, TilePXSize);
	mapDim = mapDimensions;
	shaderPath = shader;
	
	map = new Tile** [mapDim.y];
	for (int i = 0; i < mapDim.y; i++)
	{
		map[i] = new Tile*[mapDim.x];
		
	}

	Tile* temp;
	for (int i = 0; i < mapDim.y; i++)
	{
		for (int j = 0; j < mapDim.x; j++)
		{
			temp = new Tile(shader);
			temp->SetTexture(texPath);
			temp->transform.SetScale(0.125f);
			temp->transform.SetPosition({ (0.125f * j)-0.875f,(0.125f * i)-0.875f, 0.0f });
			

			map[i][j] = temp;

		}
	}	
}

Tilemap::~Tilemap() {
	for (int i = 0; i < mapDim.y; ++i) {
		delete[] map[i];
	}
	delete[] map;
	delete basesheet;
}

void Tilemap::GenerateMapFromVec(const std::vector<int>& vec)
{
	int tempI = 0;

	for (int i = 0; i < mapDim.y; i++)
	{
		for (int j = 0; j < mapDim.x; j++)
		{
			basesheet->SetTilebyID(map[i][j], vec[tempI]);
			tempI++;
		}
	}
}

Tile* Tilemap::getTile(int x, int y)
{
	return map[y][x];
}

Tile* Tilemap::getTile(Vector2 tileCoord)
{
	int x = tileCoord.x;
	int y = tileCoord.y;
	return map[y][x];
}

spritesheet* Tilemap::getSheet()
{
	return basesheet;
}

Vector2 Tilemap::GetMapDim()
{
	return mapDim;
}

void Tilemap::TurnUnwalkableByID(int id)
{
	for (int i = 0; i < mapDim.y-1; i++) // -1 so it doesnt break out of the array
	{
		for (int j = 0; j < mapDim.x-1; j++)
		{
			if (map[j][i]->GetId() == id)
				map[j][i]->SetIsWalkable(false);

		}
	}
}

void Tilemap::Draw() {
	for (int i = 0; i < mapDim.y; ++i) {
		for (int j = 0; j < mapDim.x; ++j) {
			map[i][j]->Draw();
		}
	}
}
