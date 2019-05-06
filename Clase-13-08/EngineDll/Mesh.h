#pragma once
#include "Entity.h"
#include "Material.h"
#include "Exports.h"

#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006

class ENGINEDLL_API Mesh :
	public Entity
{
public:
protected:
	bool _shouldDispose;
	Material* _material;

	//Shape---------------------------
	float* _vertex;
	unsigned int _bufferId;
	int _vertexCant;
	
	//Index---------------------------
	unsigned int* _index;
	unsigned int _indexBufferId;
	int _indexCant;

public:
	Mesh(Renderer * rend);
	void Draw();
	void Dispose(unsigned int bufferID, float* vertex);
	void SetMaterial(Material* mat);
	void SetVertex(float* vertex, int vertexCant, unsigned int* index, int indexCant);

	~Mesh();
};

