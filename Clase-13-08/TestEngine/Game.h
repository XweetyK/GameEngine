#pragma once
#include "../EngineDll/GameBase.h"
#include <iostream>
#include "../EngineDll/Triangle.h"
#include "../EngineDll/Entity.h"
using namespace std;
class Game : public GameBase
{
private:
	Triangle* _triangle;
	Material* _material;
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

