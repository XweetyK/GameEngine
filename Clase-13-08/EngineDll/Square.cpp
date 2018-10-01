#include "Square.h"

Square::Square(Renderer* render, Material* mat) :Entity(renderer) {
	shouldDispose = false;
	_vertex = NULL;
	_bufferId = -1;
	_material = mat;

	_vertex = new float[12]{
		-0.5f, -0.5f, 0.f,
		-0.5f,  0.5f, 0.f,
		0.5f, -0.5f, 0.f,
		0.5f,  0.5f, 0.f
	};
	SetVertex(_vertex, 4);
}
Square::~Square() {
}
void Square::Draw() {
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
void Square::SetVertex(float* vertex, int vertexCant) {
	Dispose();
	_vertex = vertex;
	shouldDispose = true;
	_vertexCant = vertexCant;
	_bufferId = renderer->GenBuffer(_vertex, sizeof(float)* vertexCant * 3);
}
void Square::Dispose() {
	if (shouldDispose) {
		renderer->DestroyBuffer(_bufferId);
		delete[] _vertex;
		shouldDispose = false;
	}
}