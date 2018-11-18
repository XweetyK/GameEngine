#pragma once
#include "../EngineDll/GameBase.h"
#include <iostream>
#include "../EngineDll/Triangle.h"
#include "../EngineDll/Square.h"
#include "../EngineDll/Sprite.h"
#include "../EngineDll/Entity.h"
#include "../EngineDll/Animator.h"
#include "GLFW\glfw3.h"
using namespace std;
class Game : public GameBase
{
private:
	Shape* _triangle;
	Material* _trgMat;
	Shape* _square;
	Material* _sqrMat;
	Sprite* _sprite;
	Material* _sprtTexture;
	Sprite* _cris;
	Material* _crisTexture;
	Animator* _animator;
	float _trgVel;
	float _sqrVel;
	float _trgRot;
	float _sqrRot;
	float _pos;
	float _scale;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate(double deltaTime) override;
	void onDraw() override;
public:
	Game();
	~Game();
	int _i;
};

