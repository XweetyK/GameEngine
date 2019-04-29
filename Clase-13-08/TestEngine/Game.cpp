#include "Game.h"


Game::Game()
{

}
Game::~Game()
{
}
bool Game::onStart() {
	_cam = new Camera();
	_cam->Start(renderer);

	_mat = Material::LoadMaterial(VERTEX_SHADER_PATH, FRG_SHADER_PATH);
	_tri = new Triangle(renderer);
	float* _vertices = new float[9]{
		0.8f,-0.8f,0.0f,
		0.5f,-0.2f,0.0f,
		0.2f,-0.8f,0.0f
	};
	_tri->SetVertex(_vertices, 3);
	_tri->SetMaterial(_mat);


	return true;
}

bool Game::onStop() {
	return true;
}
bool Game::onUpdate(double deltaTime) {
	Input(deltaTime);
	_cam->Update();
	return true;
}
void Game::onDraw() {
	_tri->Draw();
}
void Game::Input(double deltaTime) {
	if (input(UP_INPUT)) {
		_cam->Walk(1 * deltaTime);
	}
	if (input(DOWN_INPUT)) {
		_cam->Walk(-1 * deltaTime);
	}
	if (input(LEFT_INPUT)) {
		_cam->Strafe(-1 * deltaTime);
	}
	if (input(RIGHT_INPUT)) {
		_cam->Strafe(1 * deltaTime);
	}
	if (input(W_INPUT)) {
		_cam->Ascend(1 * deltaTime);
	}
	if (input(S_INPUT)) {
		_cam->Ascend(-1 * deltaTime);
	}
	if (input(A_INPUT)) {
		_cam->Yaw(1 * deltaTime);
	}
	if (input(D_INPUT)) {
		_cam->Yaw(-1 * deltaTime);
	}
	if (input(Z_INPUT)) {
		_cam->Roll(1 * deltaTime);
	}
	if (input(X_INPUT)) {
		_cam->Roll(-1 * deltaTime);
	}
}
