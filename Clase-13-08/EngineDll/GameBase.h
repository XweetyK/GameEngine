#pragma once
#include "Exports.h"
#include "Renderer.h"
#include "Window.h"
#include "Include.h"
#include "Externals.h"
class ENGINEDLL_API GameBase
{
private:
	Renderer * renderer;
	Window * window;
protected:
	virtual bool onStart()=0;
	virtual bool onStop()=0;
	virtual bool onUpdate()=0;
public:
	GameBase();
	~GameBase();
	bool start(int alto, int ancho, string nombre);
	bool stop();
	void loop();
};

