#include "Camera.h"



Camera::Camera()
{}
Camera::~Camera()
{}

void Camera::Start(Renderer* rend) {
	_renderer = rend;
	_viewMat = rend->GetCamera();

}

void Camera::Update() {
	_renderer->SetCamera(_viewMat);
	cout << _vecUp[0] << "/" << _vecUp[1] << "/" << _vecUp[2] << endl;
}

void Camera::Walk(float z) {
}

void Camera::Strafe(float x, float y) {
}
