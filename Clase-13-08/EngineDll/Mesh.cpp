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
void Mesh::SetVertex(float* vertex, int vertexCant, unsigned int* index, int indexCant) {
	Dispose(_bufferId, _vertex);
	_vertex = vertex;
	_shouldDispose = true;
	_vertexCant = vertexCant;
	_index = index;
	_indexCant = indexCant;

	_bufferId = renderer->GenBuffer(_vertex, sizeof(float)* vertexCant * 3);
	_indexBufferId = renderer->GenIndexBuffer(_index, sizeof(unsigned int)* indexCant);
}
