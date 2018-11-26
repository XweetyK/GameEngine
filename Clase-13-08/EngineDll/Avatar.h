#pragma once
#include "Renderer.h"
#include "Externals.h"
#include "Exports.h"
#include "Sprite.h"
#include "Entity.h"
#include "Shape.h"
#include "Animator.h"
#include "BoxCollider.h"
#include "Material.h"
class ENGINEDLL_API Avatar
{
protected:
	Sprite* _sprite;
	Animator* _animator;
	BoxCollider* _boxCollider;
	Material* _material;

public:
	Avatar(Renderer* renderer);
	~Avatar();
	void SetSprite(const char* BMPfile);
	void DrawSprite();
	void SetSpritePos(float posX, float posY, float posZ);
	void SetSpriteRot(float rotX, float rotY, float rotZ);
	void SetSpriteScale(float scaleX, float scaleY, float scaleZ);
	void SetAnimator(int frameW, int frameH, int textureW, int textureH, int* frames, int framesCant, double speed);
	void SetBoxCollider(float width, float height, float mass, float offsetX, float offsetY);
	void UpdateAvatar(double deltatime, bool animated);
	BoxCollider* GetBoxCollider() { return _boxCollider; };
};

