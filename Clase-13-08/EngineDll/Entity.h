#pragma once
#include "Exports.h"
#include "Renderer.h"
class Entity
{
protected:
	Renderer* renderer;
public:
	virtual void Draw() = 0;
	Entity(Renderer* renderer);
	~Entity();
};

