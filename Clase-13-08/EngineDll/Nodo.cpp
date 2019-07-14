#include "Nodo.h"



Nodo::Nodo(const char* name){
	_name = name;
}

Nodo::~Nodo(){
}

void Nodo::AddChild(Nodo* newChild) {
	bool repeated = false;
	vector<Nodo*>::iterator it;

	for (it= _childs.begin(); it != _childs.end(); it++){
		if (*it==newChild){
			repeated = true;
		}
	}
	if (!repeated){
		_childs.push_back(newChild);
		cout << "Child added successfully." << endl;
	}
	else { cout << "Invalid Operation: The node you're trying to add is already a child." << endl; }
}

void Nodo::RemoveChild(const char* toRemove) {
	if (_childs.size()==0){
		cout << "Invalid Operation: This node has no childs to remove." << endl;
	}
	else {
		int i = 0;
		while (_childs[i]->GetName() != toRemove && i != (_childs.size()-1)) {
			i++;
		}
		if (_childs[i]->GetName() != toRemove && i == (_childs.size()-1)) {
			cout << "Invalid Operation: The node you're trying to remove is not a child of this node." << endl;
		}
		else { _childs.erase(_childs.begin() + i);	cout << "Child removed successfully." << endl; }
	}
}

void Nodo::AddComponent(Component* newComponent) {
	bool repeated = false;
	vector<Component*>::iterator it;

	for (it = _component.begin(); it != _component.end(); it++) {
		if (*it == newComponent) {
			repeated = true;
		}
	}
	if (!repeated) {
		_component.push_back(newComponent);
		cout << "Component added successfully." << endl;
	}
	else { cout << "Invalid Operation: This node already has this component." << endl; }
}

void Nodo::RemoveComponent(const char* toRemove) {
	if (_component.size() == 0) {
		cout << "Invalid Operation: This node has no components to remove." << endl;
	}
	else {
		int i = 0;

		while (_component[i]->GetName() != toRemove && i != (_component.size() - 1)) {
			i++;
		}
		if (_component[i]->GetName() != toRemove && i == (_component.size() - 1)) {
			cout << "Invalid Operation: This node doesn't have this component." << endl;
		}
		else { _component.erase(_component.begin() + i);	cout << "Component removed successfully." << endl; }
	}
}

void Nodo::Draw() {
	glm::mat4 myMat;
}
