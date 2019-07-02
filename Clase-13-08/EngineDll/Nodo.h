#pragma once
#include "Exports.h"
#include "Include.h"
#include "Component.h"

class ENGINEDLL_API Nodo {
public:
	Nodo();
	~Nodo();

	void AddChild(Nodo newChild);
	void AbortChild();
	void AddComponent();
	void RemoveComponent();

	void Draw();
	void Update();
private:
	vector<Nodo> Childs;
	vector<Component> Component;
};

