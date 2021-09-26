#include "BaseGame.h"

void main() 
{
	BaseGame* game = new BaseGame();

	game->Init();
	game->LaunchGod();
	game->Terminate();

	delete game;
}