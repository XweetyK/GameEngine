#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}
bool Game::onStart() {
	_triangle = new Triangle(renderer);
	float* _vertices = new float[9]{
		-1.0f,1.0f,0.0f,
		1.0f,1.0f,0.0f,
		0.0f,-1.0f,0.0f
	};
	_triangle->SetVertex(_vertices, 3);
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
void Game::onDraw() {
	_triangle->Draw();
}
