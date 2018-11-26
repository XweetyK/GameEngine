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
	_sprtMov = 0;
	_pos = 0;
	_scale = 8;
	_trgVel = 0.5;
	_sqrVel = 1.0;
	_sprtVel = -3.0;
	_activated = false;

	_collisionManager = new CollisionManager(2);

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

	_ambTexture = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
	_ambulancia = new Sprite(renderer);
	_ambulancia->LoadBMP(TEXTURE_AMBULANCE_PATH);
	float* _ambVertex = new float[12]{
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};
	_ambulancia->SetVertex(_ambVertex, 4);
	_ambulancia->SetMaterial(_ambTexture);

	_cris = new Avatar(renderer);
	_cris->SetSprite(TEXTURE_A_CRISANIM_PATH);
	int* _frames = new int[4]{
		0,1,2,3,
	};
	_damageFrames = new int[2]{
		23,50
	};
	_cris->SetAnimator(128, 128, 1024, 1024, _frames, 4, 5);
	_cris->SetBoxCollider(5.0f, 5.0f, 1.0f, 0.0f, 0.0f, false);

	_cris2 = new Avatar(renderer);
	_cris2->SetSprite(TEXTURE_A_CRISANIM_PATH);
	int* _frames2 = new int[6]{
		27,26,25,
		24,39,38,
	};
	_punchFrames = new int[5] {
		45,44,43,
		42,41
	};
	_cris2->SetAnimator(128, 128, 1024, 1024, _frames2, 6, 10);
	_cris2->SetBoxCollider(5.0f, 5.0f, 3.0f, 0.0f, 0.0f, false);
	
	cout << "game::start()" << endl;
	_i = 0;

	_triangle->SetPos(_pos, 0.0f, -8.0f);
	_triangle->SetScale(_scale, _scale, _scale);

	_square->SetPos(0.0f, 0.0f, -15.0f);
	_square->SetScale(_scale, _scale, _scale);

	_sprite->SetPos(-7.0f, 7.f, 0.0f);
	_sprite->SetScale(4, 4, 4);

	_ambulancia->SetPos(5.0f, -5.0f, -0.1f);
	_ambulancia->SetScale(8, 8, 8);

	_cris->SetSpriteScale(_scale, _scale, _scale);
	_cris->SetSpritePos(-5.0f, -5.0f, 0.1f);
	_cris2->SetSpriteScale(_scale, _scale, _scale);
	_cris2->SetSpritePos(5.0f, -5.0f, -0.1f);

	_collisionManager->AddEntity(_cris->GetBoxCollider(), 0);
	_collisionManager->AddEntity(_cris2->GetBoxCollider(), 1);

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
	_sprtMov += deltaTime*_sprtVel;
	
	_triangle->SetRot(0.0f, 0.0f, _trgRot);
	_square->SetRot(_sqrRot,0.0f, _sqrRot);

	if (_collisionManager->IsColliding()) {
		if (!_activated) {
			_cris->SetAnimatorFrames(_damageFrames, 2, 10);
			_cris2->SetAnimatorFrames(_punchFrames, 5, 10);
			_activated = true;
		}
	}
	else { _activated = false; }

	_cris->UpdateAvatar(deltaTime,true);
	_cris2->UpdateAvatar(deltaTime, true);
	
	_ambulancia->SetPos(70 + _sprtMov*2.5f, _ambulancia->GetPosY(), _ambulancia->GetPosZ());
	_cris2->SetSpritePos(10+_sprtMov, _cris->GetSprite()->GetPosY(), _cris->GetSprite()->GetPosZ());
	_collisionManager->CheckLayers();

	
	
	if (_i > 5) {
		return false;
	}
	return true;
}
void Game::onDraw() {
	_triangle->Draw();
	_square->Draw();
	_sprite->Draw();
	_ambulancia->Draw();
	_cris2->DrawSprite();
	_cris->DrawSprite();
}
