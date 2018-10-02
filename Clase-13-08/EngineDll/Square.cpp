#include "Square.h"

Square::Square(Renderer* render) : Shape(render) {

	_vertex = new float[12]{
		-0.5f, -0.5f, 0.f,
		-0.5f,  0.5f, 0.f,
		0.5f, -0.5f, 0.f,
		0.5f,  0.5f, 0.f
	};
	_colorVertex = new float[12]{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
	};

	SetVertex(_vertex, 4);
	SetColorVertex(_colorVertex, 4);
}
Square::~Square() {
}
void Square::Draw() {
	if (_shouldDispose) {
		renderer->LoadIMatrix();
		renderer->SetMMatrix(_modelMat);
		if (_material) {
			_material->Bind();
			_material->SetMatrixProperty(renderer->GetMVP());
		}
		renderer->DrawBuffer(_bufferId, _vertexCant,0);
		renderer->DrawBuffer(_colorBufferId, _colorVertexCant, 1);
	}
}
void Square::SetVertex(float* vertex, int vertexCant) {
	Dispose(_bufferId, _vertex);
	_vertex = vertex;
	_shouldDispose = true;
	_vertexCant = vertexCant;
	_bufferId = renderer->GenBuffer(_vertex, sizeof(float)* vertexCant * 3);
}
void Square::SetColorVertex(float* vertex, int vertexCant) {
	Dispose(_colorBufferId, _colorVertex);
	_colorVertex = vertex;
	_shouldDispose = true;
	_colorVertexCant = vertexCant;
	_bufferId = renderer->GenColorBuffer(_vertex, sizeof(float)* vertexCant * 3);
}