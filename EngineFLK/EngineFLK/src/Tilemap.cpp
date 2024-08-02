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

	adjTiles =
	{
		getTile(convertedPosX, convertedPosY + 1),
		getTile(convertedPosX+1, convertedPosY),
		getTile(convertedPosX, convertedPosY - 1),
		getTile(convertedPosX-1, convertedPosY),
		getTile(convertedPosX+1, convertedPosY + 1),
		getTile(convertedPosX + 1, convertedPosY-1),
		getTile(convertedPosX-1, convertedPosY - 1),
		getTile(convertedPosX - 1, convertedPosY+1)
		
	};

	//std::cout << "Player world location: X: " << actor->transform.GetPosition().x << " Y: " << actor->transform.GetPosition().y << std::endl;
#if _DEBUG
	if (Input::GetKey(KeyCode::ENTER)) {
		std::cout << "Player tile location: " << convertedPosX << ":" << convertedPosY << std::endl;

	}

	if (Input::GetKey(KeyCode::ALPHA_1)) {
		std::cout << "Player tile location: " << (int)convertedPosX << ":" << (int)convertedPosY << std::endl;
		std::cout << "Player world location: " << actor->transform.GetPosition().ToString()<<std::endl;	
		std::cout<<"Tile world position: " << getTile(0, 0)->transform.GetPosition().ToString() << std::endl;
		std::cout << "--------------" << std::endl;
	}
	
#endif
	

	for (int i = 0; i < adjTiles.size(); i++)
	{
		
		/*int tileX = static_cast<int>(adjTiles[i].x);
		int tileY = static_cast<int>(adjTiles[i].y);*/

		if (CollisionWithAdjTile(actor, adjTiles[i]))
		{
			//std::cout << "Map tile location: " << tileX << ":" << tileY << std::endl;

			if (actor->TriggerCollision(adjTiles[i]))
				return true;
			break;
		}
	}

	return false;
}

//bool Tilemap::CollisionWithAdjTile(Entity2D* actor, Vector2 tile)
bool Tilemap::CollisionWithAdjTile(Entity2D* actor, Tile* tile)
{
		if (!tile->GetIsWalkable() && collisionManager->CheckCollision(actor, tile))
		{
			std::cout << "Colisiono con el tile:"<< std::endl;
			return true;
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
