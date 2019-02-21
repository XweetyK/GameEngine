#include "GameBase.h"
#include "GLFW\glfw3.h"

GameBase::GameBase()
{}

GameBase::~GameBase()
{}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		cout << key << endl;
	}
}

bool GameBase::start(int alto, int ancho, string nombre)
{
	cout << "GameBase::start()" << endl;
	renderer = new Renderer();
	window = new Window();
	if (!window->start(alto, ancho, nombre)) {
		return false;
	}
	glfwSetKeyCallback((GLFWwindow*)window->getter(), key_callback);
	glfwSetInputMode((GLFWwindow*)window->getter(), GLFW_STICKY_KEYS, 1);
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
	double timer = 0;
	double lastTimer = 0;
	double dt = 0;
	timer = lastTimer = glfwGetTime();
	do {
		timer = glfwGetTime();
		dt = timer - lastTimer;
		lastTimer = timer;

		window->pollEvents();
		res = !window->shouldClose();
		renderer->ClearWindow();
		onDraw();
		renderer->SwapBuffer();
		onUpdate(dt);
	} while (res);
}



bool GameBase::input(int key) {
	int state = glfwGetKey((GLFWwindow*)window->getter(), key);
	if (state == GLFW_PRESS && state != lastState) {
		return true;
	}
	return false;
}