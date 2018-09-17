#pragma once
#include "GameBase.h"
#include <iostream>
#include "Triangle.h"
using namespace std;
class Game : public GameBase
{
private:
	Triangle* _triangle;
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

