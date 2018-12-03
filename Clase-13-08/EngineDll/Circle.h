#pragma once
#include "Shape.h"
#include "Exports.h"
#include "Material.h"
class ENGINEDLL_API Circle :
	public Shape
{
public:
	Circle(Renderer* render, int cantTriangle, float radio);
	~Circle();
	void Draw();
	void MakeCircle();
	void SetColor(float* solidColor);
	void SetColorVertex(float* vertex, int vertexCant);
};

