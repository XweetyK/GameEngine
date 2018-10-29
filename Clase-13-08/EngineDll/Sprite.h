#pragma once
#include "Shape.h"
#include "Exports.h"
#include "Include.h"

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
public:
	Sprite(Renderer* render);
	~Sprite();
	unsigned int LoadBMP(const char * BMPfile);
	void Draw() override;
	void SetTextureVertex(float* vertex, int vertexCant);
};

