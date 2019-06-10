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
#include "../EngineDll/Camera.h"
#include "../EngineDll/Mesh.h"
#include "../EngineDll/ImporterMdl.h"

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

	ImporterMdl* _importer;
	Triangle* _tri;
	//Mesh* _mish;
	Mesh* _cube;
	Material* _mat;
	Camera* _cam;
	Game();
	~Game();
	void Input(double deltaTime);
	int _i;
};

