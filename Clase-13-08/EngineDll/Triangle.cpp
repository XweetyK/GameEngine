#include "Triangle.h"

Triangle::Triangle(Renderer* render) :Entity(renderer){
	shouldDispose = false;
	_vertex = NULL;
	_bufferId = -1;

	_vertex = new float[9]{
		-1.0f,-1.0f,0.0f,
		1.0f,-1.0f, 0.0f,
		0.0f,1.0f,0.0f
	};
	SetVertex(_vertex, 3);
}
Triangle::~Triangle(){
}
void Triangle::SetVertex(float* vertex, int count) {
	Dispose();
	_vertex = vertex;
	shouldDispose = true;

	_bufferId = renderer->genBuffer(_vertex, sizeof(float)* count * 3);
}
void Triangle::Dispose() {
	if (shouldDispose) {
		renderer->destroyBuffer(_bufferId);
		delete[] _vertex;
		shouldDispose = false;
	}
}
void Triangle::Draw() {
	if (shouldDispose) {
		renderer->drawBuffer(_bufferId, _vertexCant);
	}
}