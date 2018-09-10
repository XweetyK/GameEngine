#pragma once
#include "Entity.h"
#include "Exports.h"
class Triangle :
	public Entity
{
private:
	float* _vertex;
	unsigned int _bufferId;
	int _vertexCant;
	bool shouldDispose;
public:
	Triangle(Renderer* render);
	~Triangle();
	void SetVertex(float* vertex, int vertexCant);
	void Draw() override;
	void Dispose();
};

