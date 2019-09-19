#pragma once
#include "Exports.h"

class ENGINEDLL_API BoundingBox {

private:
	float* _vertex;
public:
	BoundingBox();
	~BoundingBox();
	void SetVertex(float* vertex);
	float* GetVertex() { return _vertex; }
};

