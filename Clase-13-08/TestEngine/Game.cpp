#include "Game.h"


Game::Game()
{

}
Game::~Game()
{
}
bool Game::onStart() {
	_ROOT = new Nodo(renderer, "root");

	_camComp = new Camera(renderer, "camara");
	_camComp->Start(renderer);
	_camara = new Nodo(renderer, "camara");
	_camara->AddComponent(_camComp);

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
	_tankMesh = _importer->GetBaseNodo();

	_tankMesh->GetComponent(0)->SetMaterial(_mat);
	_tankMesh->GetChild(0)->GetComponent(0)->SetMaterial(_mat);
	_tankMesh->GetChild(0)->GetChild(0)->GetComponent(0)->SetMaterial(_mat);


	_tankMesh->SetScale(0.2f, 0.2f, 0.2f);
	_tankMesh->SetPos(0,-0.5f,0);
	_tankMesh->GetChild(0)->SetPos(0, 2.4f, -0.5f);
	_tankMesh->GetChild(0)->GetChild(0)->SetPos(0, 0.2f, 1.0f);

	_ROOT->AddChild(_camara);
	_ROOT->AddChild(_tankMesh);

	return true;
}

bool Game::onStop() {
	return true;
}
bool Game::onUpdate(double deltaTime) {
	_tankMesh->SetRot(_tankMesh->GetRotX(), _tankMesh->GetRotY() + (deltaTime*0.2), _tankMesh->GetRotZ());
	_ROOT->Update();

	Input(deltaTime);
	return true;
}
void Game::onDraw() {
	_ROOT->Draw();
}
void Game::Input(double deltaTime) {
	if (input(UP_INPUT)) {
		_camara->GetComponent(0)->Walk(1 * deltaTime);
	}
	if (input(DOWN_INPUT)) {
		_camara->GetComponent(0)->Walk(-1 * deltaTime);
	}
	if (input(LEFT_INPUT)) {
		_camara->GetComponent(0)->Strafe(-1 * deltaTime);
	}
	if (input(RIGHT_INPUT)) {
		_camara->GetComponent(0)->Strafe(1 * deltaTime);
	}
	if (input(W_INPUT)) {
		_camara->GetComponent(0)->Ascend(1 * deltaTime);
	}
	if (input(S_INPUT)) {
		_camara->GetComponent(0)->Ascend(-1 * deltaTime);
	}
	if (input(A_INPUT)) {
		_camara->GetComponent(0)->Yaw(1 * deltaTime);
	}
	if (input(D_INPUT)) {
		_camara->GetComponent(0)->Yaw(-1 * deltaTime);
	}
	if (input(Z_INPUT)) {
		_camara->GetComponent(0)->Roll(1 * deltaTime);
	}
	if (input(X_INPUT)) {
		_camara->GetComponent(0)->Roll(-1 * deltaTime);
	}

	if (input(I_INPUT)) {
		_tankMesh->GetChild(0)->GetChild(0)->SetRot(_tankMesh->GetChild(0)->GetChild(0)->GetRotX() - (deltaTime), _tankMesh->GetChild(0)->GetChild(0)->GetRotY(), _tankMesh->GetChild(0)->GetChild(0)->GetRotZ());
	}
	if (input(K_INPUT)) {
		_tankMesh->GetChild(0)->GetChild(0)->SetRot(_tankMesh->GetChild(0)->GetChild(0)->GetRotX() + (deltaTime), _tankMesh->GetChild(0)->GetChild(0)->GetRotY(), _tankMesh->GetChild(0)->GetChild(0)->GetRotZ());
	}
	if (input(J_INPUT)) {
		_tankMesh->GetChild(0)->SetRot(_tankMesh->GetChild(0)->GetRotX(), _tankMesh->GetChild(0)->GetRotY() + (deltaTime), _tankMesh->GetChild(0)->GetRotZ());
	}
	if (input(L_INPUT)) {
		_tankMesh->GetChild(0)->SetRot(_tankMesh->GetChild(0)->GetRotX(), _tankMesh->GetChild(0)->GetRotY() - (deltaTime), _tankMesh->GetChild(0)->GetRotZ());
	}
}
