#pragma once
#include "Externals.h"
#include "Exports.h"
#include"Entity.h"
class ENGINEDLL_API BoxCollider
{
protected:
	Entity* _entity;
	float _width;
	float _height;
	float _updWRgt;
	float _updWLft;
	float _updHUp;
	float _updHDw;
	float _mass;
	float _offsetX;
	float _offsetY;
	bool _static;

public:
	BoxCollider();
	~BoxCollider();
	void AttachEntity(Entity* entity);
	void SetBoxLimits(float width, float height, float mass, float offsetX, float offsetY, bool staticness);
	void UpdateBox();
	float GetHeightUp() { return _updHUp; };
	float GetWidthUp() { return _updWLft; };
	float GetHeightDw() { return _updHDw; };
	float GetWidthDw() { return _updWRgt; };
	float GetWidthBase() { return _width; };
	float GetHeightBase() { return _height; };
	bool IsStatic() { return _static; };
	Entity* GetEntity() { return _entity; };
	float GetMass() { return _mass; };
};

