#pragma once
#include "Entity.h"
#include "Material.h"
#include "Exports.h"

class ENGINEDLL_API Shape :
	public Entity
{
protected:
	float* _vertex;
	int _vertexCant;
	unsigned int _bufferID = -1;
public:
	Shape(Renderer * render);
	void SetMaterial(Material* mat);
	void Dispose();
	
	~Shape();
};