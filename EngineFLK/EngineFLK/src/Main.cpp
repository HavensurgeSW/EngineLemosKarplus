#include "base_game/BaseGame.h"

void main() 
{
	BaseGame* game = new BaseGame();

	game->LaunchGod();

	delete game;	
}