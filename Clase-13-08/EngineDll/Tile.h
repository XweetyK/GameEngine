#pragma once
#include "Exports.h"
#include "Include.h"
#include "../EngineDll/Square.h"
#include "../EngineDll/Sprite.h"
#include "../EngineDll/Entity.h"
#include "../EngineDll/Animator.h"
#include "../EngineDll/Avatar.h"
#include "../EngineDll/CollisionManager.h"

class ENGINEDLL_API Tile
{
private:
	int _tileType;
	Avatar* _sprite;
	bool _enabled;
	bool _collide;
	bool _animated;
	int _width;
	int _height;
	bool _empty;

public:
	Tile();
	~Tile();
	void SetTileProperty(Renderer* renderer, int w, int h, const char* BMPtile, int type, bool collide);
	void DrawTile();
	void SetTilePos(float posX, float posY, float posZ);
	void SetTileScale(float scaleX, float scaleY, float scaleZ);
	void SetAnimator(int frameW, int frameH, int textureW, int textureH, int* frames, int framesCant, double speed);
	void SetAnimator(int frameW, int frameH, int textureW, int textureH, int frame);
	void SetBoxCollider(float width, float height, float mass, float offsetX, float offsetY, bool staticness);
	void UpdateAnim(double deltatime, bool animated);
	bool GetEmpty() { return _empty; }
	void SetEmpty(bool value) { _empty=value; }
	int GetType() { return _tileType; }
};

