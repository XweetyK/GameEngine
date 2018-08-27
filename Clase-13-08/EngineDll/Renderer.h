#pragma once
#include "Include.h"
class Renderer 
{
public:
	Renderer();
	~Renderer();
	bool start();
	bool stop();
	void setClearColor(float r, float g, float b, float a);
	void clearWindow();
	void swapBuffer();
};

