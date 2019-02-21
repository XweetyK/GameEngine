#pragma once
#include "Shape.h"
#include "Exports.h"
#include "Include.h"
class Frame
{
public:
	float * _vertexUV;
	Frame() {
		_vertexUV = new float[8]{
			0.0f,0.0f,
			0.0f,0.0f,
			0.0f,0.0f,
			0.0f,0.0f	
		};
	}
	void SetVertex(float u1, float u2, float v1, float v2) {
		_vertexUV[0] = u1; _vertexUV[1] = v2;
		_vertexUV[2] = u1; _vertexUV[3] = v1;
		_vertexUV[4] = u2; _vertexUV[5] = v2;
		_vertexUV[6] = u2; _vertexUV[7] = v1;
	}
	float* GetFrame() { return _vertexUV; }
};
class ENGINEDLL_API Sprite :
	public Shape
{
protected:
	// Lectura de información del encabezado del archivo
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
							  // Información RGB
	unsigned char * data;

	unsigned int _image;
	Frame* _frame;

public:
	Sprite(Renderer* render);
	~Sprite();
	unsigned int LoadBMP(const char * BMPfile);
	void Draw() override;
	void SetTextureVertex(float* vertex, int vertexCant);
	void MakeFrames(int frameWidth, int frameHeight, int textureWidth, int textureHeight);
	void SetFrame(int frame);
	void SetUvVertex(float* uvVertex, int vertexCant);
};

