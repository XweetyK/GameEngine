#pragma once

#include "Renderer.h"
#include "Exports.h"
#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>

class ENGINEDLL_API Entity
{
private:
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;

protected:
	Renderer* renderer;

	glm::mat4 _modelMat;
	glm::mat4 _translateMat;
	glm::mat4 _rotMat;
	glm::mat4 _scaleMat;
	bool _canMove;
public:
	virtual void Draw() = 0;
	Entity(Renderer* renderer);
	~Entity();
	void UpdModelMatrix();
	void SetScale(float x, float y, float z);
	void SetPos(float x, float y, float z);
	void SetRot(float x, float y, float z);
	float GetPosX() { return _position[0]; };
	float GetPosY() { return _position[1]; };
	float GetPosZ() { return _position[2]; };
	glm::vec3 GetFullPos() { return _position; };
	void CanMove(bool canMove) { _canMove = canMove; };
};

