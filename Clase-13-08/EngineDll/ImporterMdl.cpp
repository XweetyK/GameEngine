#include "ImporterMdl.h"

ImporterMdl::ImporterMdl(const char * ModelPath, Mesh* mesh) {

	Assimp::Importer _importer;
	_mesh = mesh;

	_scene = _importer.ReadFile(ModelPath, 
		aiProcess_Triangulate |
		aiProcess_GenSmoothNormals |
		aiProcess_FlipUVs |
		aiProcess_JoinIdenticalVertices);

	_vertexCant = _scene->mMeshes[0]->mNumVertices;
	_indexCant = (_scene->mMeshes[0]->mNumFaces)*3;
	_uvCant = _vertexCant;

	LoadValues();
}

void ImporterMdl::LoadValues() {
	float* _vertex = new float[_vertexCant * 3];
	int ver = 0;
	for (int i = 0; i < _vertexCant; i++)
	{
		_vertex[ver++] = _scene->mMeshes[0]->mVertices[i].x;
		_vertex[ver++] = _scene->mMeshes[0]->mVertices[i].y;
		_vertex[ver++] = _scene->mMeshes[0]->mVertices[i].z;
	}

	unsigned int* _index = new unsigned int[_indexCant];
	int ind = 0;
	for (int i = 0; i < _scene->mMeshes[0]->mNumFaces; i++)
	{
		_index[ind++] = _scene->mMeshes[0]->mFaces[i].mIndices[0];
		_index[ind++] = _scene->mMeshes[0]->mFaces[i].mIndices[1];
		_index[ind++] = _scene->mMeshes[0]->mFaces[i].mIndices[2];
	}

	float* _texture = new float[_uvCant * 2];
	int tex = 0;
	
	for (int i = 0; i < _uvCant; i++)
	{
		_texture[tex++] = _scene->mMeshes[0]->mTextureCoords[0][i].x;
		_texture[tex++] = _scene->mMeshes[0]->mTextureCoords[0][i].y;
	}

	_mesh->SetVertex(_vertex, _vertexCant, _index, _indexCant, _texture, _uvCant);
}
