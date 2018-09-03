#pragma once
#include "Include.h"
#include "Window.h"
class Renderer 
{
private:
	Window* _window;
public:
	Renderer();
	~Renderer();
	bool start(Window* window);
	bool stop();
	void setClearColor(float r, float g, float b, float a);
	void clearWindow();
	void swapBuffer();
};

