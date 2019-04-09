#include "Game.h"


Game::Game()
{

}
Game::~Game()
{
}
bool Game::onStart() {
	_cam = new Camera();
	_cam->Start(renderer);

	_mat = Material::LoadMaterial(VERTEX_SHADER_PATH, FRG_SHADER_PATH);
	_tri = new Triangle(renderer);
	float* _vertices = new float[9]{
		0.8f,-0.8f,0.0f,
		0.5f,-0.2f,0.0f,
		0.2f,-0.8f,0.0f
	};
	_tri->SetVertex(_vertices, 3);
	_tri->SetMaterial(_mat);


	return true;
}

bool Game::onStop() {
	return true;
}
bool Game::onUpdate(double deltaTime) {
	_cam->Update();
	return true;
}
void Game::onDraw() {
	_tri->Draw();
}
