#pragma once
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "assimp/scene.h"
#include "Exports.h"
#include "Include.h"
#include "Externals.h"
#include "Mesh.h"
#include "Renderer.h"

class ENGINEDLL_API ImporterMdl
{
private:
	Mesh* _mesh;
	const aiScene* _scene;

	unsigned int _vertexCant;
	unsigned int _indexCant;
	unsigned int _uvCant;

	void LoadValues();

public:
	ImporterMdl(const char * ModelPath, Mesh* mesh);
};

