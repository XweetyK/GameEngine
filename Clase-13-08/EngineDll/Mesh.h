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

	//Circle--------------------------
	float _radio;
	float _angulo;
	float _grados;
	int _triangleCant;
	float* _color;

	//Color---------------------------
	float* _colorVertex;
	unsigned int _colorBufferId;
	int _colorVertexCant;

	//Sprite--------------------------
	float* _spriteVertex;
	unsigned int _textureBufferId;
	unsigned int _UVBufferId;
	int _spriteVertexCant;


public:
	Mesh(Renderer * rend);
	void Dispose(unsigned int bufferID, float* vertex);
	void SetMaterial(Material* mat);
	void SetVertex(float* vertex, int vertexCant);

	~Mesh();
};

