#include "Entity.h"

Entity::Entity(Renderer* renderer){
	this->renderer = renderer;

	_position[0] = _position[1] = _position[2] = 0.0f;
	_rotation[0] = _rotation[1] = _rotation[2] = 0.0f;
	_scale[0] = _scale[1] = _scale[2] = 1.0f;

	_modelMat = glm::mat4(1.0f);
	_translateMat = glm::mat4(1.0f);
	_rotMat = glm::mat4(1.0f);
	_scaleMat = glm::mat4(1.0f);
}
Entity::~Entity(){
}
void Entity::UpdModelMatrix() {
	_modelMat = _translateMat*_rotMat*_scaleMat;
}
void Entity::SetScale(float x, float y, float z) {
	_scale[0] = x;
	_scale[1] = y;
	_scale[2] = z;

	_scaleMat = glm::scale(glm::mat4(1.0f), _scale);
	UpdModelMatrix();
}
void Entity::SetPos(float x, float y, float z) {
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;

	_translateMat = glm::translate(glm::mat4(1.0f), _position);
	UpdModelMatrix();
}
void Entity::SetRot(float x, float y, float z) {
	_rotation[0] = x;
	_rotation[1] = y;
	_rotation[2] = z;

	_rotMat = glm::rotate(glm::mat4(1.0f), _rotation[0], glm::vec3(1.0f, 0.0f, 0.0f));
	_rotMat *= glm::rotate(glm::mat4(1.0f), _rotation[1], glm::vec3(0.0f, 1.0f, 0.0f));
	_rotMat *= glm::rotate(glm::mat4(1.0f), _rotation[2], glm::vec3(0.0f, 0.0f, 1.0f));
	UpdModelMatrix();
}