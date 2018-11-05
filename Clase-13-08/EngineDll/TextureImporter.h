#pragma once
#include "Exports.h"
#include "Include.h"
class ENGINEDLL_API TextureImporter
{
protected:
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
							  // Información RGB
	unsigned char * data;

	unsigned int _image;
public:
	TextureImporter(const char* BMPfile);
	~TextureImporter();
};

