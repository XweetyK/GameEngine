#include "Triangle.h"

Triangle::Triangle(Renderer* render, Material* mat) :Entity(renderer){
	shouldDispose = false;
	_vertex = NULL;
	_bufferId = -1;
	_material = mat;

	_vertex = new float[9]{
		-1.0f,-1.0f,0.0f,
		1.0f,-1.0f, 0.0f,
		0.0f,1.0f,0.0f
	};
	SetVertex(_vertex, 3);
}
Triangle::~Triangle(){
}
void Triangle::SetVertex(float* vertex, int vertexCant) {
	Dispose();
	_vertex = vertex;
	shouldDispose = true;
	_vertexCant = vertexCant;
	_bufferId = renderer->GenBuffer(_vertex, sizeof(float)* vertexCant * 3);
}
void Triangle::Dispose() {
	if (shouldDispose) {
		renderer->DestroyBuffer(_bufferId);
		delete[] _vertex;
		shouldDispose = false;
	}
}
void Triangle::Draw() {
	if (shouldDispose) {
		/*renderer->LoadIMatrix();
		renderer->SetMMatrix(_modelMat);*/
		if (_material) {
			_material->Bind();
			//_material->SetMatrixProperty(renderer->GetMVP());
		}
		renderer->DrawBuffer(_bufferId, _vertexCant);
	}
}