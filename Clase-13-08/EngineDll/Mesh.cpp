#include "Mesh.h"



Mesh::Mesh(Renderer * rend, const char* name) :Component(rend, name) {
	_shouldDispose = false;
	_bBox = new BoundingBox;
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
		if (_material) {
			_material->Bind();
			_material->SetMatrixProperty(_rend->GetMVP());
			_material->BindTexture(_textureBufferId);
		}
		
		_rend->BindBuffer(_bufferId, 0, 3);
		_rend->BindBuffer(_UVBufferId, 1, 2);
		_rend->BindIndexBuffer(_indexBufferId);
		_rend->DrawIndexBuffer(_indexCant);

		_rend->DisableArray(0);
		_rend->DisableArray(1);
	}
}
void Mesh::Dispose(unsigned int bufferID, float* vertex) {
	if (_shouldDispose) {
		_rend->DestroyBuffer(bufferID);
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

	_bufferId = _rend->GenBuffer(_vertex, sizeof(float)* vertexCant * 3);
	_indexBufferId = _rend->GenIndexBuffer(_index, sizeof(unsigned int)* indexCant);
	_textureBufferId = _rend->GenTextureBuffer(width, height, data);
	_UVBufferId = _rend->GenUVBuffer(_uvs, sizeof(float)* uvCant * 2);
}

void Mesh::SetBoundingBox(float* min, float* max){
	float* _vertex = new float[8 * 3]{
	min[0], min[1], min[2],
	min[0], min[1], max[2],
	min[0], max[1], min[2],
	min[0], max[1], max[2],
	
	max[0], max[1], min[2],
	max[0], max[1], max[2],
	max[0], min[1], min[2],
	max[0], min[1], max[2],
	};
	_bBox->SetVertex(_vertex);
}
