#pragma once
#include "../EngineDll/GameBase.h"
#include <iostream>
#include "../EngineDll/Triangle.h"
#include "../EngineDll/Square.h"
#include "../EngineDll/Entity.h"
using namespace std;
class Game : public GameBase
{
private:
	Triangle* _triangle;
	Material* _trgMat;
	Square* _square;
	Material* _sqrMat;
	float _vel;
	float _rot;
	float _pos;
	float _scale;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate() override;
	void onDraw() override;
public:
	Game();
	~Game();
	int _i;
};

