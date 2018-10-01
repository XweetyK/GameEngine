#include "GameBase.h"
#include "GLFW\glfw3.h"

GameBase::GameBase()
{}

GameBase::~GameBase()
{}

bool GameBase::start(int alto, int ancho, string nombre)
{
	cout << "GameBase::start()" << endl;
	renderer = new Renderer();
	window = new Window();
	if (!window->start(alto, ancho, nombre)) {
		return false;
	}
	if (!renderer->Start(window)) {
		return false;
	}

	return onStart();
}

bool GameBase::stop()
{
	cout << "GameBase::stop()" << endl;
	onStop();
	renderer->Stop();
	window->stop();
	return true;
}

void GameBase::loop() 
{
	bool res = true;
	renderer->SetClearColor(0.7f, 1.0f, 0.5f, 1.0f);
	do {
		window->pollEvents();
		res = !window->shouldClose();
		renderer->ClearWindow();
		onDraw();
		renderer->SwapBuffer();
		onUpdate();
	} while (res);
}