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
	// Habilidad el test de profundidad
	glEnable(GL_DEPTH_TEST);
	// Aceptar el fragmento si está más cerca de la cámara que el fragmento anterior
	glDepthFunc(GL_LESS);
	// Transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
unsigned int Renderer::GenUVBuffer(float* buffer, int size) {
	GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
	return uvbuffer;
}
void Renderer::DestroyBuffer(unsigned int buffer) {
	
}
void Renderer::BindBuffer(unsigned int vertexBuffer, unsigned int atribId, unsigned int atribSize) {
	// 1rst attribute buffer : vértices
	glEnableVertexAttribArray(atribId);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		atribId,                  // atributo 0. No hay razón particular para el 0, pero debe corresponder en el shader.
		atribSize,                  // tamaño
		GL_FLOAT,           // tipo
		GL_FALSE,           // normalizado?
		0,                    // Paso
		(void*)0            // desfase del buffer
	);
}
void Renderer::DrawBuffer(int size, unsigned int drawStyle) {
	// Dibujar el triángulo !
	glDrawArrays(drawStyle, 0, size); // Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
}
void Renderer::DisableArray(unsigned int atribId) {
	glDisableVertexAttribArray(atribId);
}
unsigned int Renderer::GenColorBuffer(float* buffer, int size) {
	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
	return colorbuffer;
}
/*void Renderer::DrawColorBuffer(unsigned int colorbuffer) {
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
}*/
unsigned int Renderer::GenTextureBuffer(unsigned int width, unsigned int height, unsigned char * data) {
// Creamos una textura OpenGL
GLuint textureID;
glGenTextures(1, &textureID);

// "Bind" the newly created texture : all future texture functions will modify this texture
glBindTexture(GL_TEXTURE_2D, textureID);

// Give the image to OpenGL
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);

// OpenGL has now copied the data. Free our own version
delete[] data;

// Poor filtering, or ...
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 

// ... nice trilinear filtering ...
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
// ... which requires mipmaps. Generate them automatically.
glGenerateMipmap(GL_TEXTURE_2D);

// Return the ID of the texture we just created
return textureID;
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
void Renderer::CameraPos(int x, int y) {
	_viewMat = glm::lookAt(
		glm::vec3(x, y, 3),
		glm::vec3(x, y, 0),
		glm::vec3(0, 1, 0)
	);

	UpdMVP();
}