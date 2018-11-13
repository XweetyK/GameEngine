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

	_sprtTexture = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
	_sprite = new Sprite(renderer);
	_sprite->LoadBMP(TEXTURE_SPRITE_PATH);
	float* _spriteVertex = new float[12]{
		-0.5f, -0.5f, 0.f,
		-0.5f, 0.5f, 0.f,
		0.5f, -0.5f, 0.f,
		0.5f, 0.5f, 0.f
	};
	_sprite->SetVertex(_spriteVertex, 4);
	_sprite->SetMaterial(_sprtTexture);

	_crisTexture = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
	_cris = new Sprite(renderer);
	_cris->MakeFrames(128, 128, 1024, 1024);
	
	_cris->LoadBMP(TEXTURE_CRISANIM_PATH);
	_cris->SetMaterial(_crisTexture);
	_cris->SetFrame(22);
	
	cout << "game::start()" << endl;
	_i = 0;

	_triangle->SetPos(_pos, 0.0f, 0.0f);
	_triangle->SetScale(_scale, _scale, _scale);

	_square->SetPos(0.0f, 0.0f, -10.0f);
	_square->SetScale(_scale, _scale, _scale);

	_sprite->SetPos(0.0f, 0.0f, -9.0f);
	_sprite->SetScale(_scale, _scale, _scale);

	_cris->SetScale(_scale, _scale, _scale);

	return true;
}

bool Game::onStop() {
	cout << "game::stop()" << endl;
	delete _sprite;
	delete _square;
	delete _triangle;
	delete _cris;
	return true;
}
bool Game::onUpdate(double deltaTime) {
	cout << "game::onUpdate()";
	_i++;
	cout <<_i<< endl;

	_trgRot += deltaTime*_trgVel;
	_sqrRot += deltaTime*_sqrVel;
	
	_triangle->SetRot(0.0f, 0.f, _trgRot);
	_square->SetRot(_sqrRot,0.0f, _sqrRot);
	
	if (_i > 5) {
		return false;
	}
	return true;
}
void Game::onDraw() {
	_triangle->Draw();
	_square->Draw();
	_sprite->Draw();
	_cris->Draw();
}
