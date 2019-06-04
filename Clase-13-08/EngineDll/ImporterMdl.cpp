#include "ImporterMdl.h"

ImporterMdl::ImporterMdl(Renderer* render, const char * ModelPath) {

	Assimp::Importer _importer;
	_mesh = new Mesh(render);

	const aiScene* _scene = _importer.ReadFile(ModelPath, 
		aiProcess_Triangulate |
		aiProcess_GenSmoothNormals |
		aiProcess_FlipUVs |
		aiProcess_JoinIdenticalVertices);

	unsigned int _vertexCant = _scene->mMeshes[0]->mNumVertices;
	unsigned int _indexCant = (_scene->mMeshes[0]->mNumFaces)*3;

	float* _vertex = new float[_vertexCant * 3];
	int v = 0;
	for (int i = 0; i < _vertexCant; i++)
	{
		_vertex[v++] = _scene->mMeshes[0]->mVertices[i].x; 
		_vertex[v++] = _scene->mMeshes[0]->mVertices[i].y; 
		_vertex[v++] = _scene->mMeshes[0]->mVertices[i].z;
	}

	unsigned int* _index = new unsigned int[_indexCant];
	int _cant = 0;
	for (int i = 0; i < _scene->mMeshes[0]->mNumFaces; i++)
	{
		for (int j = 0; j < _scene->mMeshes[0]->mFaces[i].mNumIndices; j++)
		{
			_index[_cant] = _scene->mMeshes[0]->mFaces[i].mIndices[j];
			_cant++;
			cout << _cant << endl;
		}
	}

	_mesh->SetVertex(_vertex, _vertexCant, _index, _indexCant);

	for (int i = 0; i < _indexCant; i++)
	{
		cout << _index[i] << "/";
	}

}

void ImporterMdl::DrawMesh() {
	
}

Mesh* ImporterMdl::GetMesh() {
	return(_mesh);
}
