 #include "Square.h"

Square::Square(Renderer* render) : Shape(render) {

	_vertex = new float[12]{
		-0.5f, -0.5f, 0.f,
		-0.5f,  0.5f, 0.f,
		0.5f, -0.5f, 0.f,
		0.5f,  0.5f, 0.f
	};
	_colorVertex = new float[12]{
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f
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
		renderer->DrawColorBuffer(_colorBufferId, _colorVertexCant);
	}
}

void Square::SetColorVertex(float* vertex, int vertexCant) {
	_colorVertex = vertex;
	_shouldDispose = true;
	_colorVertexCant = vertexCant;
	_colorBufferId = renderer->GenColorBuffer(_colorVertex, sizeof(float)* vertexCant * 3);
}