#pragma once
#include "Exports.h"
#include "Include.h"
#include "Renderer.h"
#include "Material.h"

class ENGINEDLL_API Component {
protected:
	const char* _name;
	Renderer * _rend;
	glm::mat4 * _modelMat;

public:
	Component(Renderer* rend, const char* name);
	~Component();
	void SetRenderer(Renderer* rend);

	virtual void Draw() {};
	virtual void Update() {};
	void SetName(const char* newName);
	const char* GetName() { return _name; }
	void SetModelMat(glm::mat4* mat);

	//Mesh-------------------------
	virtual unsigned int LoadBMP(const char * BMPfile) { return 0; };
	virtual void SetMaterial(Material* mat) {};
	virtual void SetVertex(float* vertex, int vertexCant, unsigned int* index, int indexCant, float* uv, int uvCant) {};

	//Camera-----------------------
	virtual void Start(Renderer * rend) {};
	virtual void Walk(float z) {};
	virtual void Strafe(float x) {};
	virtual void Ascend(float y) {};

	virtual void Pitch(float rotX) {};
	virtual void Yaw(float rotY) {};
	virtual void Roll(float rotZ) {};
};

