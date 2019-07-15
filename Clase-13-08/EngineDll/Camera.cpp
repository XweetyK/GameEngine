#include "Camera.h"

Camera::Camera(Renderer * rend, const char* name) :Component(rend, name)
{}
Camera::~Camera()
{}

void Camera::Start(Renderer* rend) {
	_renderer = rend;
}

void Camera::Walk(float z) {
	_eye += z * _forwardVec;
	_center += z * _forwardVec;
	Update();
}
void Camera::Strafe(float x) {
	_eye += x * _rightVec;
	_center += x * _rightVec;
	Update();
}
void Camera::Ascend(float y) {
	_eye += y * _upVec;
	_center += y * _upVec;
	Update();
}

void Camera::Pitch(float rotX) {
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotX, glm::vec3(_rightVec.x, _rightVec.y, _rightVec.z));

	_forwardVec = rot * _forwardVec;
	_up = rot * _up;

	_center = _eye + _forwardVec;

	Update();
}
void Camera::Yaw(float rotY) {
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotY, glm::vec3(_up.x, _up.y, _up.z));

	_forwardVec = rot * _forwardVec;
	_rightVec = rot * _rightVec;

	_center = _eye + _forwardVec;

	Update();
}
void Camera::Roll(float rotZ) {
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotZ, glm::vec3(_forwardVec.x, _forwardVec.y, _forwardVec.z));

	_up = rot * _up;
	_rightVec = rot * _rightVec;

	_center = _eye + _forwardVec;

	Update();
}

void Camera::Update() {
	_viewMat = glm::lookAt(
		(glm::vec3)_eye, 
		(glm::vec3)_center, 
		(glm::vec3)_up
	);
	_renderer->SetCamera(_viewMat);
}
