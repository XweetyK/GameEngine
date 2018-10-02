#include "Shape.h"

Shape::Shape(Renderer* render):Entity(render){
	_shouldDispose = false;
	_vertex = NULL;
	_bufferId = -1;
	_material = NULL;
}

Shape::~Shape(){
}

void Shape::Dispose(unsigned int bufferID, float* vertex){
	if (_shouldDispose) {
		renderer->DestroyBuffer(bufferID);
		delete[] vertex;
		_shouldDispose = false;
	}
}
void Shape::SetMaterial(Material* mat) {
	_material = mat;
}