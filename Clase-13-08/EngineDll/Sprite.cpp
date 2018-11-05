#include "Sprite.h"

Sprite::Sprite(Renderer* render) : Shape(render){
	//LoadBMP(TEXTURE_PATH);-->llamar al inicializar en game;

	_vertex = new float[12]{
		-0.5f, -0.5f, 0.f,
		-0.5f,  0.5f, 0.f,
		0.5f, -0.5f, 0.f,
		0.5f,  0.5f, 0.f
	};
	SetVertex(_vertex, 4);

	_spriteVertex = new float[8]{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};
}

Sprite::~Sprite(){
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

	// Algunos archivos BMP tienen un mal formato, así que adivinamos la información faltante
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : un byte por cada componente Rojo (Red), Verde (Green) y Azul(Blue)
	if (dataPos == 0)      dataPos = 54; // El encabezado del BMP está hecho de ésta manera
										 // Se crea un buffer
	data = new unsigned char[imageSize];

	// Leemos la información del archivo y la ponemos en el buffer
	fread(data, 1, imageSize, file);

	//Todo está en memoria ahora, así que podemos cerrar el archivo
	fclose(file);
}
void Sprite::Draw() {
	if (_shouldDispose) {
		renderer->LoadIMatrix();
		renderer->SetMMatrix(_modelMat);
		if (_material) {
			_material->Bind();
			_material->SetMatrixProperty(renderer->GetMVP());
			_material->BindTexture(_textureBufferId);
		}
		renderer->BindBuffer(_bufferId, 0, 3);
		renderer->BindBuffer(_UVBufferId, 1, 2);
		renderer->DrawBuffer(_vertexCant, GL_TRIANGLE_STRIP);
		renderer->DisableArray(0);
		renderer->DisableArray(1);
	}
}
void Sprite::SetTextureVertex(float* vertex, int vertexCant) {
	_spriteVertex = vertex;
	_shouldDispose = true;
	_spriteVertexCant = vertexCant;
	_textureBufferId = renderer->GenTextureBuffer(width, height, data);
	_UVBufferId = renderer->GenUVBuffer(_vertex, sizeof(float)* vertexCant * 2);
}
