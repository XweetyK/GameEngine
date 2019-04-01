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


using namespace std;
class Game : public GameBase
{
private:


protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate(double deltaTime) override;
	void onDraw() override;

public:
	void Camera(int x, int y);
	Game();
	~Game();
	int _i;
};

