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
	if (!renderer->start()) {
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
	return onStop();
}

void GameBase::loop() 
{
	bool res = true;
	do {
		window->pollEvents();
		res = !window->shouldClose();
		onUpdate();
	} while (res);
}