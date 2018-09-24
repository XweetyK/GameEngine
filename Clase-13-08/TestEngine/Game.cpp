#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}
bool Game::onStart() {
	_material = Material::LoadMaterial(VERTEX_SHADER_PATH, PIXEL_SHADER_PATH);
	_triangle = new Triangle(renderer,_material);
	float* _vertices = new float[9]{
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f,
		-0.5f,-0.5f,0.0f
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
