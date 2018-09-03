#pragma once
#include "Entity.h"
class Triangle :
	public Entity
{
private:
	int _vertex;
	unsigned int _bufferId;
public:
	Triangle();
	~Triangle();
};

