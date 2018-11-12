#pragma once
#include "Shape.h"
#include "Exports.h"
#include "Include.h"
class Frame
{
public:
	float * _vertexUV;
	void SetVertex(float a, float b, float c, float d) {
		_vertexUV[0] = a;
		_vertexUV[1] = b;
		_vertexUV[2] = c;
		_vertexUV[3] = d;
	}
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
	void SetFrames(int frameWidth, int frameHeight, int textureWidth, int textureHeight);
};

