#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}
bool Game::onStart() {
	_rot = 0;
	_pos = 0;
	_scale = 8;
	_vel = 0.5;

	_trgMat = Material::LoadMaterial(VERTEX_SHADER_PATH, FRG_SHADER_PATH);
	_triangle = new Triangle(renderer);
	float* _vertices = new float[9]{
		0.8f,-0.8f,0.0f,
		0.5f,-0.2f,0.0f,
		0.2f,-0.8f,0.0f
	};
	_triangle->SetVertex(_vertices, 3);
	_triangle->SetMaterial(_trgMat);

	_sqrMat = Material::LoadMaterial(COLOR_VERTEX_SHADER_PATH, COLOR_FRG_SHADER_PATH);
	_square = new Square(renderer);
	float* _sqrVertices = new float[12]{
		-0.8f, 0.8f, 0.f,
		-0.8f, 0.2f, 0.f,
		-0.2f, 0.8f, 0.f,
		-0.2f, 0.2f, 0.f
	};
	_square->SetVertex(_sqrVertices, 4);
	_square->SetMaterial(_sqrMat);
	cout << "game::start()" << endl;
	_i = 0;
	return true;
}

bool Game::onStop() {
	cout << "game::stop()" << endl;
	return true;
}
bool Game::onUpdate(double deltaTime) {
	cout << "game::onUpdate()";
	_i++;
	cout <<_i<< endl;

	_rot += deltaTime*_vel;
	
	_triangle->SetRot(0.0f, 0.f, _rot);
	_triangle->SetPos(_pos, 0.0f, 0.0f);
	_triangle->SetScale(_scale, _scale, _scale);

	_square->SetRot(_rot, 0.0f, 0.0f);
	_square->SetScale(_scale, _scale, _scale);
	if (_i > 5) {
		return false;
	}
	return true;
}
void Game::onDraw() {
	_triangle->Draw();
	_square->Draw();
}
