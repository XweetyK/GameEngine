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
		-0.8f, 0.8f, 0.0f,
		-0.8f, 0.2f, 0.0f,
		-0.2f, 0.8f, 0.0f,
		-0.2f, 0.2f, 0.0f
	};
	_square->SetVertex(_sqrVertices, 4);
	_square->SetMaterial(_sqrMat);

	_sprtTexture = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
	_sprite = new Sprite(renderer);
	_sprite->LoadBMP(TEXTURE_SPRITE_PATH);
	float* _spriteVertex = new float[12]{
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};
	_sprite->SetVertex(_spriteVertex, 4);
	_sprite->SetMaterial(_sprtTexture);

	_cris = new Avatar(renderer);
	_cris->SetSprite(TEXTURE_A_CRISANIM_PATH);
	int* _frames = new int[14]{
		17,18,19,
		20,21,22,
		1,10,11,
		12,13,14,
		15,16
	};
	_cris->SetAnimator(128, 128, 1024, 1024, _frames, 14, 10);
	_cris->SetBoxCollider(2.0f, 2.0f, 1.0f, 0.0f, 0.0f);

	_cris2 = new Avatar(renderer);
	_cris2->SetSprite(TEXTURE_A_CRISANIM_PATH);
	int* _frames2 = new int[14]{
		46,45,44,
		43,42,41,
		31,37,36,
		35,34,33,
		32,47
	};
	_cris2->SetAnimator(128, 128, 1024, 1024, _frames2, 14, 10);
	_cris2->SetBoxCollider(2.0f, 2.0f, 1.0f, 0.0f, 0.0f);
	
	cout << "game::start()" << endl;
	_i = 0;

	_triangle->SetPos(_pos, 0.0f, 0.0f);
	_triangle->SetScale(_scale, _scale, _scale);

	_square->SetPos(0.0f, 0.0f, -10.0f);
	_square->SetScale(_scale, _scale, _scale);

	_sprite->SetPos(-7.0f, 7.f, -9.0f);
	_sprite->SetScale(4, 4, 4);

	_cris->SetSpriteScale(_scale, _scale, _scale);
	_cris->SetSpritePos(-5.0f, -5.0f, 0.1f);
	_cris2->SetSpriteScale(_scale, _scale, _scale);
	_cris2->SetSpritePos(5.0f, -5.0f, 0.1f);

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

	_cris->UpdateAvatar(deltaTime,true);
	_cris2->UpdateAvatar(deltaTime, true);
	
	if (_i > 5) {
		return false;
	}
	return true;
}
void Game::onDraw() {
	_triangle->Draw();
	_square->Draw();
	_sprite->Draw();
	_cris->DrawSprite();
	_cris2->DrawSprite();

}
