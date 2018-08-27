#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}
bool Game::onStart() {
	cout << "game::start()" << endl;
	_i = 0;
	return true;
}

bool Game::onStop() {
	cout << "game::stop()" << endl;
	return true;
}
bool Game::onUpdate() {
	cout << "game::onUpdate()";
	_i++;
	cout <<_i<< endl;

	if (_i > 5) {
		return false;
	}
	return true;
}
