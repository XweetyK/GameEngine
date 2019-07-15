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



	_mat = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
	float* _vertices = new float[9]{
		0.8f,-0.8f,0.0f,
		0.5f,-0.2f,0.0f,
		0.2f,-0.8f,0.0f
	};

	string* _BMPs = new string[3]{
	TANK_CAR_TEXTURE_PATH,
	TANK_CABIN_TEXTURE_PATH,
	TANK_CANNON_TEXTURE_PATH
	};

	_importer = new ImporterMdl(renderer,TANK_MODEL_PATH,_BMPs);
	_nodo = _importer->GetBaseNodo();

	_nodo->GetComponent(0)->SetMaterial(_mat);
	_nodo->GetChild(0)->GetComponent(0)->SetMaterial(_mat);
	_nodo->GetChild(0)->GetChild(0)->GetComponent(0)->SetMaterial(_mat);


	_nodo->SetScale(0.2f, 0.2f, 0.2f);
	_nodo->SetPos(0,-0.5f,0);
	_nodo->GetChild(0)->SetPos(0, 2.4f, -0.5f);
	_nodo->GetChild(0)->GetChild(0)->SetPos(0, 0.2f, 1.0f);

	return true;
}

bool Game::onStop() {
	return true;
}
bool Game::onUpdate(double deltaTime) {
	_nodo->SetRot(_nodo->GetRotX(), _nodo->GetRotY() + (deltaTime*0.2), _nodo->GetRotZ());

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
	if (input(I_INPUT)) {
		_nodo->GetChild(0)->GetChild(0)->SetRot(_nodo->GetChild(0)->GetChild(0)->GetRotX() - (deltaTime), _nodo->GetChild(0)->GetChild(0)->GetRotY(), _nodo->GetChild(0)->GetChild(0)->GetRotZ());
	}
	if (input(K_INPUT)) {
		_nodo->GetChild(0)->GetChild(0)->SetRot(_nodo->GetChild(0)->GetChild(0)->GetRotX() + (deltaTime), _nodo->GetChild(0)->GetChild(0)->GetRotY(), _nodo->GetChild(0)->GetChild(0)->GetRotZ());
	}
	if (input(J_INPUT)) {
		_nodo->GetChild(0)->SetRot(_nodo->GetChild(0)->GetRotX(), _nodo->GetChild(0)->GetRotY() + (deltaTime), _nodo->GetChild(0)->GetRotZ());
	}
	if (input(L_INPUT)) {
		_nodo->GetChild(0)->SetRot(_nodo->GetChild(0)->GetRotX(), _nodo->GetChild(0)->GetRotY() - (deltaTime), _nodo->GetChild(0)->GetRotZ());
	}
}
