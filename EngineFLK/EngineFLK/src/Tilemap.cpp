#include "Tilemap.h"
#include "Color.h";

Tilemap::Tilemap()
{
	initMap();
	convertedPosX = 0;
	convertedPosY = 0;
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

//void Tilemap::CheckCollision(Entity2D& object) 
//{
//
//	convertedPosX = object.transform.GetPosition().x + (_width / 2) * _tileWidth;
//	convertedPosY = object.transform.GetPosition().y - (_height / 2) * _tileHeight;
//
//	int left_tile = convertedPosX / _tileWidth;
//	int right_tile = (convertedPosX + object.transform.GetScale().x) / _tileWidth;
//
//	int top_tile = (convertedPosY / _tileHeight) * -1;
//	int bottom_tile = ((convertedPosY - object.transform.GetScale().y) / _tileHeight) * -1; // Se resta porque el eje Y crece hacia arriba
//
//	if (left_tile < 0)
//		left_tile = 0;
//
//	if (right_tile >= _width)
//		right_tile = _width - 1;
//
//	if (top_tile < 0)
//		top_tile = 0;
//
//	if (bottom_tile >= _height)
//		bottom_tile = _height - 1;
//
//	/*
//	cout << "converted X: " << convertedPosX << endl;
//	cout << "converted Y: " << convertedPosY << endl;
//
//	cout << "left: " <<left_tile << endl;
//	cout << "right: "<<right_tile << endl;
//	cout << "top: " << top_tile << endl;
//	cout << "bottom: "<<bottom_tile << endl;
//	*/
//
//	for (int i = left_tile; i <= right_tile; i++) {
//
//		for (int j = top_tile; j <= bottom_tile; j++) {
//
//			for (int k = 0; k < _tileMapGrid.size(); k++) {
//				//cout << "caminable " << "[" << k << "]" << "[" << j << "]" << "[" << i << "] : "<< _tileMapGrid[k][j][i].isWalkable() << endl; // true == 1  ; false == 0
//				//cout << true << endl;
//				if (!_tileMapGrid[k][j][i].isWalkable()) {
//
//					if (_tileMapGrid[k][j][i].checkCollision(object) == CollisionHorizontalRight ||
//						_tileMapGrid[k][j][i].checkCollision(object) == CollisionHorizontalLeft)
//						object.returnToPreviusPosH();
//
//					if (_tileMapGrid[k][j][i].checkCollision(object) == CollisionVerticalUp)
//						object.returnToPreviusPos(object.posX(), object.previusPosY() + 0.2);
//
//					else if (_tileMapGrid[k][j][i].checkCollision(object) == CollisionVerticalDown)
//						object.returnToPreviusPos(object.posX(), object.previusPosY() - 0.2);
//				}
//			}
//		}
//	}
//}

