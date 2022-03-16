#include "Tilemap.h"
#include "Color.h";

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
			
			Shader shader("res/shaders/Sprite.shader");
			board[i][j].sprite = new Sprite(shader);
			board[i][j].sprite->SetTexture("res/textures/center.png");
			board[i][j].pos.x = j;
			board[i][j].pos.y = i;
			board[i][j].isWalkable = true;

			//SHAMELESSLY PULLED FROM MY OTHER PROJECT
			board[i][j].convertedPos = {static_cast<float>(aux), static_cast<float>(aux2)};
			aux += 0.5f;
			board[i][j].sprite->transform.SetScale(0.5f);
			board[i][j].sprite->transform.SetPosition(board[i][j].convertedPos);

			board[i][j].id = 10; //10 is well outside any of the IDs used for the game.
			tiles.push_back(board[i][j]);
		}
		aux = -0.5f;
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

Tile Tilemap::GetTile(int x, int y) const
{
	return board[y][x];
}

void Tilemap::SetTileID(int x, int y, int id)
{
	board[y][x].id = id;

	switch (id)
	{
	case 1:
		//board[y][x].sprite->SetColorTint(Color::Red());
		board[y][x].isWalkable = false;
		break;

	case 2:
		//board[y][x].sprite->SetColorTint(Color::Green());
		board[y][x].isWalkable = true;
		break;

	default:
		//board[y][x].sprite->SetColorTint(Color::White());
		board[y][x].isWalkable = true;
		break;
	}
}

void Tilemap::Draw()
{
	for (int i = 0; i < maxTLY; i++)
	{
		for (int j = 0; j < maxTLX; j++)
		{
			if (board[i][j].isWalkable)
			{
				board[i][j].sprite->Draw();
			}
		}
	}
}


