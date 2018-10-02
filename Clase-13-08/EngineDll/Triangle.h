#pragma once
#include "Shape.h"
#include "Exports.h"
#include "Material.h"
class ENGINEDLL_API Triangle :
	public Shape
{
public:
	Triangle(Renderer* render);
	~Triangle();
	void SetVertex(float* vertex, int vertexCant);
	void Draw() override;

};