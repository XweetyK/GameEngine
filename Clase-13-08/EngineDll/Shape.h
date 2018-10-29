#pragma once
#include "Entity.h"
#include "Material.h"
#include "Exports.h"

#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006

class ENGINEDLL_API Shape :
	public Entity
{
protected:
	bool _shouldDispose;
	Material* _material;
	float* _vertex;
	float* _colorVertex;
	float* _spriteVertex;
	unsigned int _bufferId;
	unsigned int _colorBufferId;
	unsigned int _spriteBufferId;
	int _vertexCant;
	int _colorVertexCant;
	int _spriteVertexCant;
	
	
public:
	Shape(Renderer * render);
	void Dispose(unsigned int bufferID,float* vertex);
	void SetMaterial(Material* mat);
	void SetVertex(float* vertex, int vertexCant);
	
	~Shape();
};