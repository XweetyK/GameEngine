#include "Mesh.h"



Mesh::Mesh(Renderer * rend) :Entity(rend) {
	_shouldDispose = false;
	_vertex = NULL;
	_bufferId = -1;
	_material = NULL;
	_index = NULL;
	_indexBufferId = -1;

	_vertex = new float[12]{
		-0.5f, -0.5f, 0.f,
		-0.5f,  0.5f, 0.f,
		0.5f, -0.5f, 0.f,
		0.5f,  0.5f, 0.f
	};
}

Mesh::~Mesh()
{
}
void Mesh::Draw() {
	if (_shouldDispose) {
		renderer->LoadIMatrix();
		renderer->SetMMatrix(_modelMat);
		if (_material) {
			_material->Bind();
			_material->SetMatrixProperty(renderer->GetMVP());
		}
		
		renderer->BindBuffer(_bufferId, 0, 3);
		renderer->BindIndexBuffer(_indexBufferId);
		renderer->DrawIndexBuffer(_indexCant);

		renderer->DisableArray(0);
	}
}
void Mesh::Dispose(unsigned int bufferID, float* vertex) {
	if (_shouldDispose) {
		renderer->DestroyBuffer(bufferID);
		delete[] vertex;
		_shouldDispose = false;
	}
}
void Mesh::SetMaterial(Material* mat) {
	_material = mat;
}
unsigned int Mesh::LoadBMP(const char * BMPfile) {

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
	if (imageSize == 0)    imageSize = width * height * 3; // 3 : un byte por cada componente Rojo (Red), Verde (Green) y Azul(Blue)
	if (dataPos == 0)      dataPos = 54; // El encabezado del BMP está hecho de ésta manera
										 // Se crea un buffer
	data = new unsigned char[imageSize];

	// Leemos la información del archivo y la ponemos en el buffer
	fread(data, 1, imageSize, file);

	//Todo está en memoria ahora, así que podemos cerrar el archivo
	fclose(file);
}

void Mesh::SetVertex(float* vertex, int vertexCant, unsigned int* index, int indexCant, float* uv, int uvCant) {
	Dispose(_bufferId, _vertex);
	_vertex = vertex;
	_shouldDispose = true;
	_vertexCant = vertexCant;
	_index = index;
	_indexCant = indexCant;
	_uvs = uv;
	_textureCant = uvCant;

	_bufferId = renderer->GenBuffer(_vertex, sizeof(float)* vertexCant * 3);
	_indexBufferId = renderer->GenIndexBuffer(_index, sizeof(unsigned int)* indexCant);
	_textureBufferId = renderer->GenTextureBuffer(width, height, data);
	_UVBufferId = renderer->GenUVBuffer(_uvs, sizeof(float)* uvCant * 2);
}
