#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

#define VERTEX_SHADER_PATH "Shaders/SimpleVertexShader.svs"
#define FRG_SHADER_PATH "Shaders/SimpleFragmentShader.sfs"
#define COLOR_VERTEX_SHADER_PATH "Shaders/ColorVertexShader.cvs"
#define COLOR_FRG_SHADER_PATH "Shaders/ColorFragmentShader.cfs"
#define TEXTURE_FRG_SHADER_PATH "Shaders/TextureFragmentShader.tfs"
#define TEXTURE_VERTEX_SHADER_PATH "Shaders/TextureVertexShader.tvs"

#define UP_INPUT 265
#define DOWN_INPUT 264
#define LEFT_INPUT 263
#define RIGHT_INPUT 262
#define Z_INPUT 88
#define X_INPUT 90
using namespace std;