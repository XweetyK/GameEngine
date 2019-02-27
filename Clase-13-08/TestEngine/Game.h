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
#include "Player.h"
#define TILESET_PATH "Assets/Level/Tileset.bmp"
#define TILEMAP_PATH "Assets/Level/Level.oel"
#define GEM_PATH "Assets/Level/Gems.bmp"
#define WIN_PATH "Assets/Level/Winner.bmp"
#define LOSE_PATH "Assets/Level/Loser.bmp"
#define RED_PATH "Assets/level/LosingScreen.bmp"
#define TUTO_PATH "Assets/level/Tutorial.bmp"

using namespace std;
class Game : public GameBase
{
private:

	Player* _player;

	CollisionManager* _collisionManager;
	TilemapManager* _tilemap;

	Sprite* _winnerScreen;
	Sprite* _loserScreen;
	Material* _mat;
	Sprite* _red;
	Sprite* _red2;
	Sprite* _tutorial;

	Avatar* _gem;

	float _gameTime;

	int _mapX;
	int _mapY;
	int _x;
	int _y;
	float _lastPosX;
	float _lastPosY;

	float _timer;
	int _mapLimitY;
	int _mapLimitX;

	int _gemCont;
	bool _winner;


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
	void Input(double deltaTime);
	void CheckWinner();
	void GemMovement();
	void AdjustUIPos();
};

