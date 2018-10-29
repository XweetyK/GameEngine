#include "Sprite.h"

Sprite::Sprite(Renderer* render) : Shape(render)
{
}

Sprite::~Sprite()
{
}
unsigned int Sprite::LoadBMP(const char * BMPfile) {

	FILE * file;
	fopen_s(&file, BMPfile, "rb");
	if (!file) { printf("Image could not be opened\n"); return true; }
	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return 0;
	}
	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}

	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	// Algunos archivos BMP tienen un mal formato, as� que adivinamos la informaci�n faltante
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : un byte por cada componente Rojo (Red), Verde (Green) y Azul(Blue)
	if (dataPos == 0)      dataPos = 54; // El encabezado del BMP est� hecho de �sta manera
										 // Se crea un buffer
	data = new unsigned char[imageSize];

	// Leemos la informaci�n del archivo y la ponemos en el buffer
	fread(data, 1, imageSize, file);

	//Todo est� en memoria ahora, as� que podemos cerrar el archivo
	fclose(file);
	return 1;
}
