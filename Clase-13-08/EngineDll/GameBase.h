#pragma once
#include "Exports.h"
#include "Renderer.h"
#include "Window.h"
#include "Include.h"
#include "Externals.h"
#include "GLFW/glfw3.h"

class ENGINEDLL_API GameBase
{
protected:
	virtual bool onStart()=0;
	virtual bool onStop()=0;
	virtual bool onUpdate(double deltaTime)=0;
	virtual void onDraw() = 0;
	Renderer * renderer;
	Window * window;
public:
	GameBase();
	~GameBase();
	bool start(int alto, int ancho, string nombre);
	bool stop();
	void loop();
};

