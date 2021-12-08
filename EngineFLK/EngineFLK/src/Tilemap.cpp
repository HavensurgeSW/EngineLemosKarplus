#include "Tilemap.h"

Tilemap::Tilemap()
{
	initMap();
}

Tilemap::~Tilemap()
{
}

void Tilemap::initMap()
{
	float aux = -0.5f;
	float aux2 = -0.5f;

	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			board[i][j].pos.x = j;
			board[i][j].pos.y = i;

			//SHAMELESSLY PULLED FROM MY OTHER PROJECT
			board[i][j].convertedPos = {static_cast<float>(j+aux), static_cast<float>(i+aux2)};
			aux += 0.5f;

			board[i][j].id = 10; //10 is well outside any of the IDs used for the game.
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


