#pragma once
#include "Entity.h"
#include "Material.h"
#include "Exports.h"

#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006

class ENGINEDLL_API Mesh :
	public Entity
{
protected:
	bool _shouldDispose;
	Material* _material;

	//Shape---------------------------
	float* _vertex;
	unsigned int _bufferId;
	int _vertexCant;
	
	//Index---------------------------
	unsigned int* _index;
	unsigned int _indexBufferId;
	int _indexCant;

	//UVs-----------------------------
	float* _uvs;

	// Lectura de información del encabezado del archivo
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
							  // Información RGB
	unsigned char * data;

	unsigned int _image;

public:
	Mesh(Renderer * rend);
	void Draw();
	void Dispose(unsigned int bufferID, float* vertex);
	void SetMaterial(Material* mat);
	void SetVertex(float* vertex, int vertexCant, unsigned int* index, int indexCant);
	void SetUv(float* uvs);

	~Mesh();
};

