#pragma once
#include"Exports.h"
#include "Externals.h"
#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include "Include.h"
class ENGINEDLL_API Material
{
private:
	unsigned int _programID;
	unsigned int _matrixID;
	
	Material();
	unsigned int LoadShaders(const char* vertex_file_path, const char* fragment_file_path);

public:
	~Material();
	static Material* LoadMaterial(const char* vtxShaderPath, const char* frgShaderPath);
	void SetMatrixProperty(glm::mat4& mat);
	void Bind();
	void BindTexture(unsigned int texId);
};

