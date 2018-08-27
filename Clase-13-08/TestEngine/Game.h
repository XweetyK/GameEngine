#pragma once
#include "GameBase.h"
#include <iostream>
using namespace std;
class Game : public GameBase
{
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate() override;
public:
	Game();
	~Game();
	int _i;
};

