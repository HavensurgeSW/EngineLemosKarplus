#include "Tilemap.h"


Tilemap::Tilemap(){
	basesheet = new spritesheet("", {0,0}, {0,0});
	

}

Tilemap::Tilemap(const std::string& texPath, Vector2 sheetPXSize,Vector2 TilePXSize, float transformScale, Vector2 mapDimensions, Shader shader) {
	basesheet = new spritesheet(texPath, sheetPXSize, TilePXSize);
	mapDim = mapDimensions;
	shaderPath = shader;
	tileScale = transformScale;
	
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
			temp->transform.SetScale(tileScale);
			temp->transform.SetPosition({ ((tileScale * j)-1.0f)+temp->transform.GetScale().x/2,((tileScale * i) - 1.0f) + temp->transform.GetScale().y / 2, 0.0f});
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

void Tilemap::MakeOuterWallUnwalkable()
{
	int rows = mapDim.y;
	if (rows == 0) return;
	int cols = mapDim.x;
	if (cols == 0) return;

	for (int col = 0; col < cols; ++col) {
		map[0][col]->SetIsWalkable(false); // Top row
		map[rows - 1][col]->SetIsWalkable(false); // Bottom row
	}

	for (int row = 1; row < rows - 1; ++row) {
		map[row][0]->SetIsWalkable(false); // Left column
		map[row][cols-1]->SetIsWalkable(false); // Right column
	}
}

void Tilemap::MakeOuterWallWithID(int id)
{
	int rows = mapDim.y;
	if (rows == 0) return;
	int cols = mapDim.x;
	if (cols == 0) return;

	for (int col = 0; col < cols; ++col) {
		basesheet->SetTilebyID(map[0][col], id);
		basesheet->SetTilebyID(map[rows - 1][col],id); 
		map[0][col]->SetId(id);
		map[rows - 1][col]->SetId(id);

	}

	for (int row = 1; row < rows - 1; ++row) {
		basesheet->SetTilebyID(map[row][0], id); 
		basesheet->SetTilebyID(map[row][cols-1], id); 
		map[row][0]->SetId(id);
		map[row][cols-1]->SetId(id);
	}

}


void Tilemap::Draw() {
	for (int i = 0; i < mapDim.y; ++i) {
		for (int j = 0; j < mapDim.x; ++j) {
			map[i][j]->Draw();
		}
	}
}

