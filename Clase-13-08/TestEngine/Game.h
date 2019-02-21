#pragma once
#include "../EngineDll/GameBase.h"
#include <iostream>
#include "../EngineDll/Triangle.h"
#include "../EngineDll/Square.h"
#include "../EngineDll/Sprite.h"
#include "../EngineDll/Entity.h"
#include "../EngineDll/Animator.h"
#include "../EngineDll/Avatar.h"
#include "../EngineDll/Circle.h"
#include "../EngineDll/CollisionManager.h"
#include "../EngineDll/TilemapManager.h"
#include "GLFW\glfw3.h"
using namespace std;
class Game : public GameBase
{
private:
	Shape* _triangle;
	Material* _trgMat;

	Square* _square;
	Material* _sqrMat;

	Circle* _circle;
	Material* _cirMat;

	Sprite* _sprite;
	Material* _sprtTexture;

	Sprite* _ambulancia;
	Material* _ambTexture;

	Avatar* _cris;
	Avatar* _cris2;

	CollisionManager* _collisionManager;
	TilemapManager* _tilemap;


	float _trgVel;
	float _sqrVel;
	float _sprtVel;
	float _trgRot;
	float _sqrRot;
	float _sprtMov;
	float _pos;
	float _scale;

	//-------animation test-------
	int* _damageFrames;
	int* _punchFrames;
	bool _activated;

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

