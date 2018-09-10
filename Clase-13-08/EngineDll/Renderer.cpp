#include "Renderer.h"
#include "GL\glew.h"
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
	if (glewInit() != GLEW_OK) {
		return false;
	}
	glGenVertexArrays(1, &_vertexarrayID);
	glBindVertexArray(_vertexarrayID);
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
unsigned int Renderer::genBuffer(float* buffer, int size) {
	// Identificar el vertex buffer
	unsigned int vertexbuffer;
	// Generar un buffer, poner el resultado en el vertexbuffer que acabamos de crear
	glGenBuffers(1, &vertexbuffer);
	// Los siguientes comandos le darán características especiales al 'vertexbuffer' 
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Darle nuestros vértices a  OpenGL.
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

	return vertexbuffer;
}
void Renderer::destroyBuffer(unsigned int buffer) {
	
}
void Renderer::drawBuffer(unsigned int vertexBuffer, int size) {
	// 1rst attribute buffer : vértices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // atributo 0. No hay razón particular para el 0, pero debe corresponder en el shader.
		3,                  // tamaño
		GL_FLOAT,           // tipo
		GL_FALSE,           // normalizado?
		0,                    // Paso
		(void*)0            // desfase del buffer
	);
	// Dibujar el triángulo !
	glDrawArrays(GL_TRIANGLES, 0, size); // Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
	glDisableVertexAttribArray(0);
}
