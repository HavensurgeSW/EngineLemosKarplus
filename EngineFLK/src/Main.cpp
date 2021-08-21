#include "BaseGame.h"

void main() {
	BaseGame* game = new BaseGame;
	game->launchGod();
	//game->launchGodTest();
	delete game;	
}