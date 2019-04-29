#pragma once
#include "Exports.h"
#include "Include.h"
#include "Renderer.h"

class ENGINEDLL_API Camera
{
private:

	Renderer * _renderer;

	glm::mat4 _viewMat;

	glm::vec4 _eye = { 0, 0, 3, 1 };
	glm::vec4 _center = { 0, 0, 0, 1 };
	glm::vec4 _up = { 0,1,0,0 };
	glm::vec4 _forwardVec = { 0,0,-1,0 };
	glm::vec4 _rightVec = { 1,0,0,0 };
	glm::vec4 _upVec = { 0,1,0,0 };
	

public:
	Camera();
	~Camera();

	void Start(Renderer * rend);
	void Walk(float z);
	void Strafe(float x);
	void Ascend(float y);

	void Pitch(float rotX);	
	void Yaw(float rotY);
	void Roll(float rotZ);

	void Update();
};

