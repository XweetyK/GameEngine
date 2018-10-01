#pragma once
#include "Shape.h"
#include "Exports.h"
#include "Material.h"
class ENGINEDLL_API Triangle :
	public Shape
{
private:
	float* _vertex;
	unsigned int _bufferId;
	int _vertexCant;
	bool shouldDispose;
	Material* _material;
public:
	Triangle(Renderer* render, Material* mat);
	~Triangle();
	void SetVertex(float* vertex, int vertexCant);
	void Draw() override;
	void Dispose();
};

