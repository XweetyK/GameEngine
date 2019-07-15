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

	virtual void Draw() = 0;
	virtual unsigned int LoadBMP(const char * BMPfile)=0;
	virtual void SetMaterial(Material* mat)=0;
	void SetName(const char* newName);
	const char* GetName() { return _name; }
	void SetModelMat(glm::mat4* mat);
};

