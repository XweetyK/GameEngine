#include "Game.h" 
#include <iostream>
using namespace std;

int main()
{
	Game* game = new Game();
	
	if (game->start(640,960,"Ventanita :D"))
	{
		game->loop();
	}
	game->stop();

	cin.get();
	delete game;
	return 0;
}