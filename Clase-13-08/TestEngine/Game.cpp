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

	
	_nodo= new Nodo(renderer, "parent");
	_noditoA= new Nodo(renderer, "child a");

	_componentA = new Mesh(renderer, "cube a");
	_componentB = new Mesh(renderer, "cube b");

	_nodo->AddChild(_noditoA);

	_nodo->AddComponent(_componentA);
	_noditoA->AddComponent(_componentB);


	_mat = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
	float* _vertices = new float[9]{
		0.8f,-0.8f,0.0f,
		0.5f,-0.2f,0.0f,
		0.2f,-0.8f,0.0f
	};
	_componentA->LoadBMP(TANK_CAR_TEXTURE_PATH);
	_componentB->LoadBMP(CUBE_TEXTURE_PATH);

	_importer = new ImporterMdl(TANK_MODEL_PATH, (Mesh*)_componentA);
	_importer = new ImporterMdl(MODEL_PATH, (Mesh*)_componentB);

	_componentA->SetMaterial(_mat);
	_componentB->SetMaterial(_mat);

	_noditoA->SetPos(5, 5, 0);

	return true;
}

bool Game::onStop() {
	return true;
}
bool Game::onUpdate(double deltaTime) {
	_nodo->SetRot(_nodo->GetRotX(), _nodo->GetRotY() + 0.5f*deltaTime, _nodo->GetRotZ());
	_noditoA->SetRot(_noditoA->GetRotX(), _noditoA->GetRotY() + 1.0f*deltaTime, _noditoA->GetRotZ() + 1.0f*deltaTime);

	Input(deltaTime);
	_cam->Update();
	return true;
}
void Game::onDraw() {
	_nodo->Draw();
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
