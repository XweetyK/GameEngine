#include "Window.h"
#include "GLFW\glfw3.h"
Window::Window() :_alto(300), _ancho(500), _nombre("Test Ventana")
{
}
Window::~Window()
{
}

bool Window::start(int alto, int ancho, string nombre) {
	cout << "Window::start()" << endl;
	_alto = alto; _ancho = ancho; _nombre = nombre;
	if (!glfwInit()){
		cout << "Failed to initialize GLFW"<<endl;
		return false;
	}

	window = glfwCreateWindow(_ancho,_alto, _nombre.c_str(), NULL, NULL);
	if (window == NULL) {
		cout << "Failed to open GLFW" << endl;
		return false;
	}
	return true;
}
bool Window::stop() {
	cout << "Window::stop()" << endl;
	if (window != NULL) {
		glfwDestroyWindow((GLFWwindow*)window);
	}
	return true;
}
void Window::pollEvents() {
	glfwPollEvents();
}
bool Window::shouldClose(){
	if (window) {
		return glfwWindowShouldClose((GLFWwindow*)window);
	}
	return true;
}