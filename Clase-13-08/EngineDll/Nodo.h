#pragma once
#include "Exports.h"
#include "Include.h"
#include "Component.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "Renderer.h"

class ENGINEDLL_API Nodo {
private:
	vector<Nodo*> _childs;
	vector<Component*> _component;

	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;

protected:
	Renderer * renderer;

	glm::mat4 _modelMat;
	glm::mat4 _translateMat;
	glm::mat4 _rotMat;
	glm::mat4 _scaleMat;
	const char* _name;

public:
	Nodo(const char* name);
	~Nodo();

	void SetName(const char* newName);
	const char* GetName() { return _name; }
	void AddChild(Nodo* newChild);
	void RemoveChild(const char* toRemove);
	void AddComponent(Component* newComponent);
	void RemoveComponent(const char* toRemove);

	void Draw();
	void Update();

};


