#include "Game.h"
#include "Assets.h"


Game::Game()
{

}
Game::~Game()
{
}
bool Game::onStart() {
	_ROOT = new Nodo(renderer, "root");

	_tank = new Nodo(renderer, "Tanque");
	_camComp = new Camera(renderer, "camara");
	_camComp->Start(renderer);
	_camara = new Nodo(renderer, "camara");
	_camara->AddComponent(_camComp);

	_mat = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);

	string* _BMPs = new string[3]{
	TANK_CAR_TEXTURE_PATH,
	TANK_CABIN_TEXTURE_PATH,
	TANK_CANNON_TEXTURE_PATH
	};
	string* _cubeTex = new string[1]{
		CUBE_TEXTURE_PATH
	};

	_importer = new ImporterMdl(renderer,TANK_MODEL_PATH,_BMPs);
	_importerCube = new ImporterMdl(renderer,CUBE_MODEL_PATH, _cubeTex);
	_tank = _importer->GetBaseNodo();
	_cube = _importerCube->GetBaseNodo();

	//Tank 1----------------------------------------------------------------------
	{
		_tank->GetComponent(0)->SetMaterial(_mat);
		_tank->GetChild(0)->GetComponent(0)->SetMaterial(_mat);
		_tank->GetChild(0)->GetChild(0)->GetComponent(0)->SetMaterial(_mat);

		_tank->SetScale(0.2f, 0.2f, 0.2f);
		_tank->SetRot(_tank->GetRotX(), _tank->GetRotY() + 9.4f, _tank->GetRotZ());
		_tank->GetChild(0)->SetPos(0, 2.4f, -0.5f);
		_tank->GetChild(0)->GetChild(0)->SetPos(0, 0.2f, 1.0f);

		_tank->SetPos(0, -1.5f, -1.5f);
	}

	//Cube Depth Test----------------------------------------------------------
	{
		_cube->GetComponent(0)->SetMaterial(_mat);
		_cube->SetPos(0, 2.5f, -10);
		_cube->SetScale(15, 10, 30);
	}

	//Root Node------------------------------------------------------------------
	_ROOT->AddChild(_camara);
	_ROOT->AddChild(_tank);
	_ROOT->AddChild(_cube);

	return true;
}

bool Game::onStop() {
	return true;
}
bool Game::onUpdate(double deltaTime) {
	//_tankMesh->SetRot(_tankMesh->GetRotX(), _tankMesh->GetRotY() + (deltaTime*0.2), _tankMesh->GetRotZ());
	_ROOT->Update();

	Input(deltaTime);
	return true;
}
void Game::onDraw() {
	_ROOT->Draw();
}
void Game::Input(double deltaTime) {

	if (input(UP_INPUT)) {
		_camara->GetComponent(0)->Walk(2 * deltaTime);
	}
	if (input(DOWN_INPUT)) {
		_camara->GetComponent(0)->Walk(-2 * deltaTime);
	}
	if (input(LEFT_INPUT)) {
		_camara->GetComponent(0)->Strafe(-2 * deltaTime);
	}
	if (input(RIGHT_INPUT)) {
		_camara->GetComponent(0)->Strafe(2 * deltaTime);
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

	//Tank Movement-----------------------------------------------

	if (input(U_INPUT)) {
		_tank->GetChild(0)->GetChild(0)->SetRot(_tank->GetChild(0)->GetChild(0)->GetRotX() - (deltaTime), _tank->GetChild(0)->GetChild(0)->GetRotY(), _tank->GetChild(0)->GetChild(0)->GetRotZ());
	}
	if (input(O_INPUT)) {
		_tank->GetChild(0)->GetChild(0)->SetRot(_tank->GetChild(0)->GetChild(0)->GetRotX() + (deltaTime), _tank->GetChild(0)->GetChild(0)->GetRotY(), _tank->GetChild(0)->GetChild(0)->GetRotZ());
	}
	if (input(J_INPUT)) {
		_tank->GetChild(0)->SetRot(_tank->GetChild(0)->GetRotX(), _tank->GetChild(0)->GetRotY() + (deltaTime), _tank->GetChild(0)->GetRotZ());
	}
	if (input(L_INPUT)) {
		_tank->GetChild(0)->SetRot(_tank->GetChild(0)->GetRotX(), _tank->GetChild(0)->GetRotY() - (deltaTime), _tank->GetChild(0)->GetRotZ());
	}

	if (input(I_INPUT)) {
		_tank->SetPos(_tank->GetPosX(), _tank->GetPosY(), _tank->GetPosZ() - (2*deltaTime));
	}
	if (input(K_INPUT)) {
		_tank->SetPos(_tank->GetPosX(), _tank->GetPosY(), _tank->GetPosZ() + (2*deltaTime));
	}
	if (input(SPACE_INPUT)) {
		_tank->SetRot(_tank->GetRotX() + (deltaTime), _tank->GetRotY(), _tank->GetRotZ());
	}
}
