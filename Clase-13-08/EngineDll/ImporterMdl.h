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
public:
	ImporterMdl(Renderer* render, const char * ModelPath);
	~ImporterMdl();

	void DrawMesh();
	Mesh* GetMesh();
};

