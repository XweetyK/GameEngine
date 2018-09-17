#pragma once
#include"Exports.h"
#include "Externals.h"
#include "glm\glm.hpp"
#include "Include.h"
class ENGINEDLL_API Material
{
private:
	unsigned int _programID;
	unsigned int matixID;
	
	Material(unsigned int programId);
	static bool LoadShaders(const char* vertex_file_path, const char* fragment_file_path, unsigned int & programId);
public:
	static Material* LoadMaterial(const char* vtxShaderPath, const char* frgShaderPath);
	void SetMatrixProperty(const char* name, glm::mat4& mat);
	void Bind();
	~Material();
};

