#pragma once
#include "Include.h"
#include "Window.h"
#include "Exports.h"
class ENGINEDLL_API Renderer
{
private:
	Window* _window;
	unsigned int _vertexarrayID;
public:
	Renderer();
	~Renderer();
	bool start(Window* window);
	bool stop();
	void setClearColor(float r, float g, float b, float a);
	void clearWindow();
	void swapBuffer();
	unsigned int genBuffer(float* buffer, int size);
	void destroyBuffer(unsigned int buffer);
	void drawBuffer(unsigned int vertexBuffer, int size);
};

