#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}
bool Game::onStart() {
	_trgRot = 0;
	_sqrRot = 0;
	_pos = 0;
	_scale = 8;
	_trgVel = 0.5;
	_sqrVel = 1.0;

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

	_sqrTxtMat = Material::LoadMaterial(COLOR_VERTEX_SHADER_PATH, COLOR_FRG_SHADER_PATH);
	_squareTexture = new Square(renderer);
	float* _sqrTxtVertices = new float[12]{
		-0.8f, 0.8f, 0.f,
		-0.8f, 0.2f, 0.f,
		-0.2f, 0.8f, 0.f,
		-0.2f, 0.2f, 0.f
	};
	_squareTexture->SetVertex(_sqrTxtVertices,4);
	_squareTexture->SetMaterial(_sqrTxtMat);
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

	_trgRot += deltaTime*_trgVel;
	_sqrRot += deltaTime*_sqrVel;
	
	_triangle->SetRot(0.0f, 0.f, _trgRot);
	_triangle->SetPos(_pos, 0.0f, 0.0f);
	_triangle->SetScale(_scale, _scale, _scale);
	_square->SetRot(_sqrRot,0.0f, _sqrRot);
	_square->SetPos(0.0f, 0.0f, -10.0f);
	_square->SetScale(_scale, _scale, _scale);
	_squareTexture->SetScale(_scale, _scale, _scale);
	if (_i > 5) {
		return false;
	}
	return true;
}
void Game::onDraw() {
	_triangle->Draw();
	_square->Draw();
	_squareTexture->Draw();
}
