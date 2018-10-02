#include "Triangle.h"

Triangle::Triangle(Renderer* render) :Shape(render){

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
	Dispose(_bufferId,_vertex);
	_vertex = vertex;
	_shouldDispose = true;
	_vertexCant = vertexCant;
	_bufferId = renderer->GenBuffer(_vertex, sizeof(float)* vertexCant * 3);
}
void Triangle::Draw() {
	if (_shouldDispose) {
		renderer->LoadIMatrix();
		renderer->SetMMatrix(_modelMat);
		if (_material) {
			_material->Bind();
			_material->SetMatrixProperty(renderer->GetMVP());
		}
		renderer->DrawBuffer(_bufferId, _vertexCant,0);
	}
}