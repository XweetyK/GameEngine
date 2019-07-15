#include "ImporterMdl.h"

ImporterMdl::ImporterMdl(Renderer* rend, const char * ModelPath, string* _textures) {

	Assimp::Importer _importer;

	_rend = rend;
	_bmps = _textures;

	_scene = _importer.ReadFile(ModelPath, 
		aiProcess_Triangulate |
		aiProcess_GenSmoothNormals |
		aiProcess_FlipUVs |
		aiProcess_JoinIdenticalVertices);

	_meshCant = _scene->mNumMeshes;
	_prevNodo = NULL;

	_vertexCant = new unsigned int[_meshCant];
	_indexCant = new unsigned int[_meshCant];
	_uvCant = new unsigned int[_meshCant];

	for (int i = 0; i < _meshCant; i++){
		_vertexCant[i] = _scene->mMeshes[i]->mNumVertices;
		_indexCant[i] = (_scene->mMeshes[i]->mNumFaces) * 3;
		_uvCant[i] = _vertexCant[i];
	}

	LoadValues();
}

void ImporterMdl::LoadValues() {

	for (int i = 0; i < _meshCant; i++){
		string s = std::to_string(i);
		char const* name = s.c_str();

		Nodo* _nodo = new Nodo(_rend, name);
		Component* _comp = new Mesh(_rend, name);
		_nodo->AddComponent(_comp);

		_comp->LoadBMP(_bmps[i].c_str());

		if (i == 0) { _baseNodo = _nodo; }
		if (_prevNodo != NULL) { _prevNodo->AddChild(_nodo); }

		float* _vertex = new float[_vertexCant[i] * 3];
		int ver = 0;
		for (int j = 0; j < _vertexCant[i]; j++){
			_vertex[ver++] = _scene->mMeshes[i]->mVertices[j].x;
			_vertex[ver++] = _scene->mMeshes[i]->mVertices[j].y;
			_vertex[ver++] = _scene->mMeshes[i]->mVertices[j].z;
		}

		unsigned int* _index = new unsigned int[_indexCant[i]];
		int ind = 0;
		for (int j = 0; j < _scene->mMeshes[i]->mNumFaces; j++){
			_index[ind++] = _scene->mMeshes[i]->mFaces[j].mIndices[0];
			_index[ind++] = _scene->mMeshes[i]->mFaces[j].mIndices[1];
			_index[ind++] = _scene->mMeshes[i]->mFaces[j].mIndices[2];
		}

		float* _texture = new float[_uvCant[i] * 2];
		int tex = 0;

		for (int j = 0; j < _uvCant[i]; j++){
			_texture[tex++] = _scene->mMeshes[i]->mTextureCoords[0][j].x;
			_texture[tex++] = _scene->mMeshes[i]->mTextureCoords[0][j].y;
		}
		_comp->SetVertex(_vertex, _vertexCant[i], _index, _indexCant[i], _texture, _uvCant[i]);
		_prevNodo = _nodo;
	}
}
