#pragma once
#include"Avatar.h"
#include "GameBase.h"
#include "TilemapManager.h"

#define MOV_POS 2
#define CRASH_SPRITE_PATH "Assets/Level/crash.bmp"

class Player
{
private:

	int * _facingUp;
	int * _facingDw;
	int * _facingLf;
	int * _facingRt;

public:
	Avatar* _player;
	Player(Renderer* rend);
	~Player();
	void Update(double deltaTime);
	void Draw();
	void SetPos(float x, float y, float z);
	void Movement(const char* facing, int x, int y);
};

