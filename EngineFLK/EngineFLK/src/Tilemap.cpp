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

void Tilemap::CheckTileCollisions(Entity2D* actor)
{
	
	Vector3 firstTilePos = map[0][0]->transform.GetPosition();
	Vector2 tileScale = { getTile(0,0)->transform.GetScale().x, getTile(0,0)->transform.GetScale().y };

	float convertedPosX = ((actor->transform.GetPosition().y - firstTilePos.y) + (getTile(0,0)->transform.GetScale().y / 2)) / getTile(0, 0)->transform.GetScale().y;
	float convertedPosY = ((actor->transform.GetPosition().x - firstTilePos.x) + (getTile(0, 0)->transform.GetScale().x / 2)) / getTile(0, 0)->transform.GetScale().x;

	Vector2 actorScale = { (actor->transform.GetScale().x / tileScale.x) / 2, 
							(actor->transform.GetScale().y / tileScale.y) / 2};
	std::cout << "Player tile location: " << (int)convertedPosX << ":" << (int)convertedPosY << std::endl;
	
	std::vector<Vector2> adjTiles =
	{
		Vector2(convertedPosX + actor->transform.GetScale().x, convertedPosY + actor->transform.GetScale().y),
		Vector2(convertedPosX - actor->transform.GetScale().x, convertedPosY + actor->transform.GetScale().y),
		Vector2(convertedPosX + actor->transform.GetScale().x, convertedPosY - actor->transform.GetScale().y),
		Vector2(convertedPosX - actor->transform.GetScale().x, convertedPosY - actor->transform.GetScale().y),
	};


	//for (int i = 0; i < adjTiles.size(); i++)
	//{
	//	if (CollisionWithATile(actor, adjTiles[i]))
	//	{
	//		//actor->TriggerCollision(_tilesVector[tiles[i].x][tiles[i].y]);
	//		break;
	//	}
	//}
}


//bool CollisionWithATile(Entity2D* actor, Vector2 tile)
//{
//
//
//	if (tile.x >= 0 && tile.y >= 0)
//	{
//		if (tile.x < MAP.size() && tile.y < tile[0])
//		{
//			if (_tilesVector[tile.x][tile.y]->GetColliderState())
//			{
//				cout << "Colisiono con el tile: " << tile.x << ":" << tile.y << endl;
//				return true;
//			}
//		}
//	}
//
//	return false;
//}

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
