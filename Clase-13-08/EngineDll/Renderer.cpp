#include "Renderer.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

bool Renderer::Start(Window* window) {
	cout << "Renderer::start()" << endl;
	_window = window;
	glfwMakeContextCurrent((GLFWwindow*)_window->getter());
	if (glewInit() != GLEW_OK) {
		return false;
	}
	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);
	_projectionMat = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.f);

	_viewMat = glm::lookAt(
		glm::vec3(0, 0, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);

	_modelMat = glm::mat4(1.0f);

	UpdMVP();
	return true;
}

bool Renderer::Stop() {
	cout << "Renderer::stop()" << endl;
		return true;
}
void Renderer::SetClearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}
void Renderer::ClearWindow() {
	glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::SwapBuffer() {
	glfwSwapBuffers((GLFWwindow*)_window->getter());
}
unsigned int Renderer::GenBuffer(float* buffer, int size) {
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
void Renderer::DestroyBuffer(unsigned int buffer) {
	
}
void Renderer::DrawBuffer(unsigned int vertexBuffer, int size, unsigned int atribId) {
	// 1rst attribute buffer : vértices
	glEnableVertexAttribArray(atribId);
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
	glDrawArrays(GL_TRIANGLE_STRIP, 0, size); // Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
	glDisableVertexAttribArray(atribId);
}
unsigned int Renderer::GenColorBuffer(float* buffer, int size) {
	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
	return colorbuffer;
}
void Renderer::DrawColorBuffer(unsigned int colorbuffer, int size) {
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(
		1,                                // Atributo. No hay razón especial para el 1, pero debe corresponder al número en el shader.
		3,                                // tamaño
		GL_FLOAT,                         // tipo
		GL_FALSE,                         // normalizado?
		0,                                // corrimiento
		(void*)0                          // corrimiento de buffer
	);
}
void Renderer::UpdMVP() {
	MVP = _projectionMat*_viewMat*_modelMat;
}
void Renderer::LoadIMatrix() {
	_modelMat = glm::mat4(1.0f);
}
void Renderer::SetMMatrix(glm::mat4 mat) {
	_modelMat = mat;
	UpdMVP();
}
void Renderer::MultiplyMMatrix(glm::mat4 mat) {
	_modelMat *= mat;
	UpdMVP();
}
glm::mat4& Renderer::GetMVP() {
	return MVP;
}