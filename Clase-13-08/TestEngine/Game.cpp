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

	//_mish = new Mesh(renderer);
	_cube = new Mesh(renderer);
	
	_nodo= new Nodo(renderer, "parent");
	_noditoA= new Nodo(renderer, "child a");
	_noditoB= new Nodo(renderer, "child b");

	_component = new Component("parent");
	_componentA = new Component("child a");
	_componentB = new Component("child b");

	_nodo->AddChild(_noditoA);
	_nodo->AddChild(_noditoB);
	_nodo->AddChild(_noditoA);
	_nodo->AddChild(_nodo);
	cout << endl;

	_nodo->RemoveChild("child a");
	_nodo->RemoveChild("child z");
	_nodo->RemoveChild("child b");
	_nodo->RemoveChild("child a");
	cout << endl;

	_nodo->AddComponent(_component);
	_nodo->AddComponent(_componentA);
	_nodo->AddComponent(_componentB);
	_nodo->AddComponent(_componentA);
	cout << endl;

	_nodo->RemoveComponent("child a");
	_nodo->RemoveComponent("child z");
	_nodo->RemoveComponent("child b");
	_nodo->RemoveComponent("child a");
	_nodo->RemoveComponent("parent");
	_nodo->RemoveComponent("parent");
	cout << endl;

	//float* _vertexmesh = new float[12]{
	//	-1.0f,-1.0f, 1.0f, // triangle 1 : begin
	//	1.0f, -1.0f, 1.0f,
	//	-1.0f, 1.0f, 1.0f,
	//	1.0f, 1.0f,1.0f,
	//};
	//unsigned int* index = new unsigned int[6]{
	//	0,1,2,
	//	2,3,0
	//};

	_mat = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
	_tri = new Triangle(renderer);
	float* _vertices = new float[9]{
		0.8f,-0.8f,0.0f,
		0.5f,-0.2f,0.0f,
		0.2f,-0.8f,0.0f
	};
	_tri->SetVertex(_vertices, 3);
	_tri->SetMaterial(_mat);
	//_mish->SetVertex(_vertexmesh, 4, index, 6);
	//_mish->SetMaterial(_mat);
	_cube->LoadBMP(CUBE_TEXTURE_PATH);
	_importer = new ImporterMdl(MODEL_PATH, _cube);

	_cube->SetMaterial(_mat);

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
	//_tri->Draw();
	//_mish->Draw();
	_cube->Draw();
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
