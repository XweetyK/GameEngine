#pragma once
#include "Shape.h"
#include "Exports.h"
#include "Material.h"
class ENGINEDLL_API Square :
	public Shape
{
private:
	float* _vertex;
	unsigned int _bufferId;
	int _vertexCant;
	bool shouldDispose;
	Material* _material;
public:
	Square(Renderer* render, Material* mat);
	~Square();
	void Draw() override;
	void SetVertex(float* vertex, int vertexCant);
	void Dispose();
};

