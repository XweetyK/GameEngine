#include "Circle.h"



Circle::Circle(Renderer* render, int cantTriangle, float radio) : Shape(render){
	_triangleCant = cantTriangle;
	_radio = radio;
	_vertexCant = _triangleCant * 3;
	_grados = 360.0f / _triangleCant;
	_angulo = 0.0f;

	_vertex = new float[_vertexCant];
	_colorVertex = new float[_vertexCant];
}

Circle::~Circle(){
}

void Circle::SetColor(float* solidColor) {
	_color = solidColor;
}

void Circle::MakeCircle() {
	glm::vec3 _vec;

	for (int i = 0; i < _vertexCant; i += 3) {
		_vec = glm::vec3(cos(_angulo), sin(_angulo), 0)* _radio;
		_vertex[i] = _vec.x;
		_colorVertex[i] = _color[0];
		_vertex[i + 1] = _vec.y;
		_colorVertex[i+1] = _color[1];
		_vertex[i + 2] = _vec.z;
		_colorVertex[i+2] = _color[3];
		_angulo += _grados * glm::pi<float>() / 180.0f;
	}
	SetVertex(_vertex, _triangleCant);
	SetColorVertex(_colorVertex, _triangleCant);
}

void Circle::Draw() {
	if (_shouldDispose) {
		renderer->LoadIMatrix();
		renderer->SetMMatrix(_modelMat);
		if (_material) {
			_material->Bind();
			_material->SetMatrixProperty(renderer->GetMVP());
		}
		renderer->BindBuffer(_bufferId, 0, 3);
		renderer->BindBuffer(_colorBufferId, 1, 3);
		renderer->DrawBuffer(_vertexCant, GL_TRIANGLE_FAN);
		renderer->DisableArray(0);
		renderer->DisableArray(1);
	}
}

void Circle::SetColorVertex(float* vertex, int vertexCant) {
	_colorVertex = vertex;
	_shouldDispose = true;
	_colorVertexCant = vertexCant;
	_colorBufferId = renderer->GenColorBuffer(_colorVertex, sizeof(float)* vertexCant * 3);
}