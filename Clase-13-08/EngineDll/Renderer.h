#pragma once
#include "Include.h"
#include "Window.h"
#include "Exports.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
class ENGINEDLL_API Renderer
{
private:
	Window* _window;
	unsigned int _vertexArrayID;
	unsigned int _colorVertexArrayID;
	glm::mat4 _modelMat;
	glm::mat4 _viewMat;
	glm::mat4 _projectionMat;
	glm::mat4 MVP;

public:
	Renderer();
	~Renderer();
	bool Start(Window* window);
	bool Stop();
	void SetClearColor(float r, float g, float b, float a);
	void ClearWindow();
	void SwapBuffer();
	unsigned int GenBuffer(float* buffer, int size);
	void DestroyBuffer(unsigned int buffer);
	void BindBuffer(unsigned int vertexBuffer, unsigned int atribId, unsigned int atribSize);
	void DrawBuffer( int size, unsigned int drawStyle);
	void DisableArray(unsigned int atribId);
	unsigned int GenColorBuffer(float* buffer, int size);
	unsigned int GenUVBuffer(float* buffer, int size);
	//void DrawColorBuffer(unsigned int vertexBuffer, int size);
	unsigned int GenTextureBuffer(unsigned int width, unsigned int height, unsigned char * data);
	//void DrawTextureBuffer(unsigned int vertexBuffer, int size);
	void UpdMVP();
	void LoadIMatrix();
	void SetMMatrix(glm::mat4 mat);
	void MultiplyMMatrix(glm::mat4 mat);
	void CameraPos(int x, int y);
	glm::mat4& GetMVP();
};

