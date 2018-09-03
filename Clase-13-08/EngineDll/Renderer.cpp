#include "Renderer.h"
#include "GLFW\glfw3.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

bool Renderer::start(Window* window) {
	cout << "Renderer::start()" << endl;
	_window = window;
	glfwMakeContextCurrent((GLFWwindow*)_window->getter());
		return true;
}

bool Renderer::stop() {
	cout << "Renderer::stop()" << endl;
		return true;
}
void Renderer::setClearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}
void Renderer::clearWindow() {
	glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::swapBuffer() {
	glfwSwapBuffers((GLFWwindow*)_window->getter());
}
