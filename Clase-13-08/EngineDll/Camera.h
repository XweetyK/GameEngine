#pragma once
#include "Exports.h"
#include "Include.h"
#include "Renderer.h"

class ENGINEDLL_API Camera
{
	Renderer* _renderer;
	glm::vec3 _vecEye {0,0,0};
	glm::vec3 _vecCenter {0,0,0};
	glm::vec3 _vecUp {0,1,0};
	glm::mat4 _viewMat;

public:
	Camera();
	~Camera();
	void Start(Renderer* rend);
	void Update();
	void Walk(float z);
	void Strafe(float x, float y);
};

