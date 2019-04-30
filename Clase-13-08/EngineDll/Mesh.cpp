#include "Mesh.h"



Mesh::Mesh(Renderer * rend) :Entity(rend) {
	_shouldDispose = false;
	_vertex = NULL;
	_bufferId = -1;
	_material = NULL;
}

Mesh::~Mesh()
{
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
void Mesh::SetVertex(float* vertex, int vertexCant) {
	Dispose(_bufferId, _vertex);
	_vertex = vertex;
	_shouldDispose = true;
	_vertexCant = vertexCant;
	_bufferId = renderer->GenBuffer(_vertex, sizeof(float)* vertexCant * 3);
}
