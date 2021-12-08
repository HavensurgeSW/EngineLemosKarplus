#include "Tilemap.h"

Tilemap::Tilemap()
{
	initMap();
}

Tilemap::~Tilemap()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		delete tiles[i].sprite;
	}
}

void Tilemap::initMap()
{
	float aux = -0.5f;
	float aux2 = -0.5f;

	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			
			Tile tile;
			Shader shader("res/shaders/Sprite.shader");
			tile.sprite = new Sprite(shader);
			tile.sprite->SetTexture("res/textures/CG2f1.png");
			board[i][j].pos.x = j;
			board[i][j].pos.y = i;
			tile.pos = board[i][j].pos;

			//SHAMELESSLY PULLED FROM MY OTHER PROJECT
			board[i][j].convertedPos = {static_cast<float>(j+aux), static_cast<float>(i+aux2)};
			tile.convertedPos = board[i][j].convertedPos;
			aux += 0.5f;
			tile.sprite->transform.SetScale(0.1f);
			tile.sprite->transform.SetPosition(tile.convertedPos);

			board[i][j].id = 10; //10 is well outside any of the IDs used for the game.
			tile.id = board[i][j].id;
			tiles.push_back(tile);
		}
		aux2 += 0.5f;
	}
}

Vector2 Tilemap::getPos(int x, int y)
{
	return board[y][x].pos;
}

Vector2 Tilemap::getConvertedPos(int x, int y)
{
	return board[y][x].convertedPos;
}

void Tilemap::Draw()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i].sprite->Draw();
	}
}


