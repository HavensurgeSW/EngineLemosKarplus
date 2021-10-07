#include "BaseGame.h"

void main()
{
	BaseGame* game = new BaseGame();

	game->InitEngine();
	game->LaunchGod();

	delete game;
}