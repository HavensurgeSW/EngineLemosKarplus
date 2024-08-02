#include "Tilemap.h"


Tilemap::Tilemap(){
	basesheet = new spritesheet("", {0,0}, {0,0});
	

}

Tilemap::Tilemap(const std::string& texPath, Vector2 sheetPXSize,Vector2 TilePXSize, Vector2 mapDimensions, Shader shader) {
	basesheet = new spritesheet(texPath, sheetPXSize, TilePXSize);
	mapDim = mapDimensions;
	shaderPath = shader;
	float scale = 0.125f;
	
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
			temp->transform.SetScale(scale);
			temp->transform.SetPosition({ ((scale * j)-1.0f)+temp->transform.GetScale().x/2,((scale * i) - 1.0f) + temp->transform.GetScale().y / 2, 0.0f});
			map[i][j] = temp;

		}
	}	

	mapSlots = mapDim.x * mapDim.y;
}

Tilemap::~Tilemap() {
	for (int i = 0; i < mapDim.y; ++i) {
		delete[] map[i];
	}
	delete[] map;
	delete basesheet;
}

void Tilemap::SetCollisionManager(CollisionManager* cm)
{
	collisionManager = cm;
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

bool Tilemap::CheckTileCollisions(Entity2D* actor)
{
	Vector3 firstTilePos = map[0][0]->transform.GetPosition();
	Vector2 tileScale = { getTile(0,0)->transform.GetScale().x, getTile(0,0)->transform.GetScale().y };
	
	
	int convertedPosX = static_cast<int>(((actor->transform.GetPosition().x + actor->transform.GetScale().x/2) - firstTilePos.x) / tileScale.x);
	int convertedPosY = static_cast<int>(((actor->transform.GetPosition().y + actor->transform.GetScale().y/2) - firstTilePos.y) / tileScale.y);

	std::vector<Vector2>adjTiles =
	{
		{(float)convertedPosX, (float)convertedPosY + 1},
		{(float)convertedPosX + 1, (float)convertedPosY},
		{(float)convertedPosX, (float)convertedPosY - 1},
		{(float)convertedPosX - 1, (float)convertedPosY},
		{(float)convertedPosX + 1, (float)convertedPosY + 1},
		{(float)convertedPosX + 1, (float)convertedPosY - 1},
		{(float)convertedPosX - 1, (float)convertedPosY - 1},
		{(float)convertedPosX - 1, (float)convertedPosY + 1}
		
	};

	for (int i = 0; i < adjTiles.size(); i++)
	{
		if (CollisionWithAdjTile(actor, adjTiles[i]))
		{
			Tile* tempTile = getTile(adjTiles[i]);
			if (actor->TriggerCollision(tempTile))
				return true;
			break;
		}
	}

	return false;
}

bool Tilemap::CollisionWithAdjTile(Entity2D* actor, Vector2 tile)
{
	if ((tile.x > 0 && tile.x < mapDim.x - 1) && (tile.y > 0 && tile.y < mapDim.y - 1)) {
		Tile* tempTile = getTile(tile);
		if (!tempTile->GetIsWalkable() && collisionManager->CheckCollision(actor, tempTile))
		{
			std::cout << "Colisiono con el tile:" << std::endl;
			return true;
		}
	}
	return false;
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

