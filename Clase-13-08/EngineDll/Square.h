#pragma once
#include "Shape.h"
#include "Exports.h"
#include "Material.h"
class ENGINEDLL_API Square :
	public Shape
{
public:
	Square(Renderer* render);
	~Square();
	void Draw() override;
	void SetColorVertex(float* vertex, int vertexCant);
};