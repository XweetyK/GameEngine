#pragma once
#include "Include.h"
class Window
{
private:
	void* window;
	int _alto;
	int _ancho;
	string _nombre;
public:
	Window();
	~Window();
	bool start(int alto, int ancho, string nombre);
	bool stop();
	void pollEvents();
	bool shouldClose();
	void* getter() { return window; };
};

