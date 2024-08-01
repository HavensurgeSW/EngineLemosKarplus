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
			temp->transform.SetPosition({ ((0.125f * j)-1.0f)+temp->transform.GetScale().x/2,((0.125f * i) - 1.0f) + temp->transform.GetScale().y / 2, 0.0f});
			//temp->transform.SetPosition({ ((0.25f * j)-1.0f),((0.25f * i)-1.0f), 0.0f});

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


	float convertedPosX = (actor->transform.GetPosition().x - firstTilePos.x) / tileScale.x;
	float convertedPosY = (actor->transform.GetPosition().y - firstTilePos.y) / tileScale.y;

	std::vector<Vector2> adjTiles =
	{
		Vector2(convertedPosX, convertedPosY+1),
		Vector2(convertedPosX + 1, convertedPosY),
		Vector2(convertedPosX, convertedPosY-1),
		Vector2(convertedPosX - 1, convertedPosY),
	};

	//std::cout << "Player world location: X: " << actor->transform.GetPosition().x << " Y: " << actor->transform.GetPosition().y << std::endl;
#if _DEBUG
	if (Input::GetKey(KeyCode::ENTER)) {
		std::cout << "Player tile location: " << (int)convertedPosX << ":" << (int)convertedPosY << std::endl;
		std::cout << "Top tile: " << (int)adjTiles[0].x << " " << (int)adjTiles[0].y << std::endl;
		std::cout << "Right tile: " << (int)adjTiles[1].x << " " << (int)adjTiles[1].y << std::endl;
		std::cout << "Bottom tile: " << (int)adjTiles[2].x << " " << (int)adjTiles[2].y << std::endl;
		std::cout << "Left tile: " << (int)adjTiles[3].x << " " << (int)adjTiles[3].y << std::endl;
	}
#endif
	

	for (int i = 0; i < adjTiles.size(); i++)
	{
		
		int tileX = static_cast<int>(adjTiles[i].x);
		int tileY = static_cast<int>(adjTiles[i].y);

		if (CollisionWithAdjTile(actor, adjTiles[i]))
		{
			std::cout << "Map tile location: " << tileX << ":" << tileY << std::endl;

			if (actor->TriggerCollision(getTile(tileX, tileY)))
				return true;
			break;
		}
	}

	return false;
}

//bool Tilemap::CollisionWithAdjTile(Entity2D* actor, Vector2 tile)
bool Tilemap::CollisionWithAdjTile(Entity2D* actor, Vector2 tile)
{

	if (tile.x >= 0 && tile.y >= 0 && tile.x < mapDim.x && tile.y < mapDim.y)
	{
		if (!getTile(tile.x,tile.y)->GetIsWalkable() && collisionManager->CheckCollision(actor, getTile(tile.x, tile.y)) )
		{
			//std::cout << "Colisiono con el tile: " << convertedPosX << ":" << convertedPosY << std::endl;
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
