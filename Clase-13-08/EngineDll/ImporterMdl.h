#pragma once
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "assimp/scene.h"
#include "Exports.h"
#include "Include.h"
#include "Externals.h"
#include "Mesh.h"
#include "Renderer.h"
#include "Nodo.h"
#include "Component.h"

class ENGINEDLL_API ImporterMdl
{
private:
	const aiScene* _scene;
	Renderer* _rend;

	Nodo* _baseNodo;
	Nodo* _prevNodo;

	string* _bmps;

	unsigned int _meshCant;
	unsigned int* _vertexCant;
	unsigned int* _indexCant;
	unsigned int* _uvCant;

	void LoadValues();

public:
	ImporterMdl(Renderer* rend, const char * ModelPath, string* _textures);
	Nodo* GetBaseNodo() { return _baseNodo; };
};

