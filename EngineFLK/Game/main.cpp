#include "Game.h"

void main() 
{
	Game* game = new Game();

	game->InitEngine();
	game->LaunchGodEngine();
	game->Terminate();

	delete game;
}