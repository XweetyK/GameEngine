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

void Triangle::Draw() {
	if (_shouldDispose) {
		renderer->LoadIMatrix();
		renderer->SetMMatrix(_modelMat);
		if (_material) {
			_material->Bind();
			_material->SetMatrixProperty(renderer->GetMVP());
		}
		renderer->BindBuffer(_bufferId, 0, 3);
		renderer->DrawBuffer(_vertexCant, GL_TRIANGLE_STRIP);
		renderer->DisableArray(0);
	}
}