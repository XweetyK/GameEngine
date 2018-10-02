#pragma once
#include "Entity.h"
#include "Material.h"
#include "Exports.h"

class ENGINEDLL_API Shape :
	public Entity
{
protected:
	bool _shouldDispose;
	Material* _material;
	float* _vertex;
	unsigned int _bufferId;
	unsigned int _colorBufferId;
	int _vertexCant;
	int _colorVertexCant;
	float* _colorVertex;
public:
	Shape(Renderer * render);
	void Dispose(unsigned int bufferID,float* vertex);
	void SetMaterial(Material* mat);
	
	~Shape();
};