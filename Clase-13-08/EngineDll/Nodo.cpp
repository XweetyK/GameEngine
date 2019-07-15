#include "Nodo.h"



Nodo::Nodo(const char* name){
	_name = name;

	_position[0] = _position[1] = _position[2] = 0.0f;
	_rotation[0] = _rotation[1] = _rotation[2] = 0.0f;
	_scale[0] = _scale[1] = _scale[2] = 1.0f;

	_modelMat = glm::mat4(1.0f);
	_translateMat = glm::mat4(1.0f);
	_rotMat = glm::mat4(1.0f);
	_scaleMat = glm::mat4(1.0f);
}

Nodo::~Nodo(){
}

void Nodo::AddChild(Nodo* newChild) {
	if (newChild==this){
		cout << "Invalid Operation: This node can't add itself as a child." << endl;
		return;
	}

	vector<Nodo*>::iterator it;

	for (it= _childs.begin(); it != _childs.end(); it++){
		if (*it==newChild){
			cout << "Invalid Operation: The node you're trying to add is already a child." << endl;
			return;
		}
	}
	_childs.push_back(newChild);
	cout << "Child added successfully." << endl;
}

void Nodo::RemoveChild(const char* toRemove) {
	if (_childs.size()==0){
		cout << "Invalid Operation: This node has no childs to remove." << endl;
		return;
	}

	int i = 0;

	for (int i = 0; i < _childs.size(); i++) {
		if (_childs[i]->GetName() == toRemove) {
			_childs.erase(_childs.begin() + i);	
			cout << "Fisrt child with that name removed successfully." << endl;
			return;
		}
	}

	cout << "Invalid Operation: The node you're trying to remove is not a child of this node." << endl;
}

void Nodo::AddComponent(Component* newComponent) {
	vector<Component*>::iterator it;

	for (it = _component.begin(); it != _component.end(); it++) {
		if (*it == newComponent) {
			cout << "Invalid Operation: This node already has this component." << endl;
			return;
		}
	}
	newComponent->SetModelMat(&_modelMat);
	_component.push_back(newComponent);
	cout << "Component added successfully." << endl;
}

void Nodo::RemoveComponent(const char* toRemove) {
	if (_component.size() == 0) {
		cout << "Invalid Operation: This node has no components to remove." << endl;
		return;
	}
	int i = 0;

	for (int i = 0; i < _component.size(); i++) {
		if (_component[i]->GetName() == toRemove) {
			_component.erase(_component.begin() + i);
			cout << "First component with that name removed successfully." << endl;
			return;
		}
	}
	cout << "Invalid Operation: The component you're trying to remove is not in this node." << endl;
}

void Nodo::Draw() {
	glm::mat4 myMat;
}

//Transformations---------------------------------------

void Nodo::UpdModelMatrix() {
	_modelMat = _translateMat * _rotMat*_scaleMat;
}
void Nodo::SetScale(float x, float y, float z) {
	_scale[0] = x;
	_scale[1] = y;
	_scale[2] = z;

	_scaleMat = glm::scale(glm::mat4(1.0f), _scale);
	UpdModelMatrix();
}
void Nodo::SetPos(float x, float y, float z) {
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;

	_translateMat = glm::translate(glm::mat4(1.0f), _position);
	UpdModelMatrix();
}
void Nodo::SetRot(float x, float y, float z) {
	_rotation[0] = x;
	_rotation[1] = y;
	_rotation[2] = z;

	_rotMat = glm::rotate(glm::mat4(1.0f), _rotation[0], glm::vec3(1.0f, 0.0f, 0.0f));
	_rotMat *= glm::rotate(glm::mat4(1.0f), _rotation[1], glm::vec3(0.0f, 1.0f, 0.0f));
	_rotMat *= glm::rotate(glm::mat4(1.0f), _rotation[2], glm::vec3(0.0f, 0.0f, 1.0f));
	UpdModelMatrix();
}