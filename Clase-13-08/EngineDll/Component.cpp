#include "Component.h"



Component::Component(Renderer* rend, const char* name){
	_rend = rend;
	_name = name;
}


Component::~Component()
{
}

void Component::SetRenderer(Renderer* rend) {
	_rend = rend;
}

void Component::SetName(const char* newName) {
	_name = newName;
}

void Component::SetModelMat(glm::mat4* mat) {
	_modelMat = mat;
}
