#include "Shape.h"

Shape::Shape(Renderer* render):Entity(render){
}

Shape::~Shape(){
	Dispose();
}

void Shape::Dispose() {
	renderer->DestroyBuffer(_bufferID);
}
//void Shape::SetMaterial(Material* mat) {
//	material = mat;
//}