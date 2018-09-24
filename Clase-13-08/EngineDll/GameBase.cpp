#include "GameBase.h"

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
	if (!renderer->start(window)) {
		return false;
	}

	return onStart();
}

bool GameBase::stop()
{
	cout << "GameBase::stop()" << endl;
	onStop();
	renderer->stop();
	window->stop();
	return true;
}

void GameBase::loop() 
{
	bool res = true;
	renderer->setClearColor(0.7f, 1.0f, 0.5f, 1.0f);
	do {
		window->pollEvents();
		res = !window->shouldClose();
		renderer->clearWindow();
		onDraw();
		renderer->swapBuffer();
		onUpdate();
	} while (res);
}