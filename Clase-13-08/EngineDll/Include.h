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

#define MODEL_PATH "Assets/Cube/Cube.obj"
#define CUBE_TEXTURE_PATH "Assets/Cube/CubeTex.bmp"

#define TANK_MODEL_PATH "Assets/Tanquesito/Tank2.obj"
#define TANK_CAR_TEXTURE_PATH "Assets/Tanquesito/car.bmp"
#define TANK_CABIN_TEXTURE_PATH "Assets/Tanquesito/cabin.bmp"
#define TANK_CANNON_TEXTURE_PATH "Assets/Tanquesito/cannon.bmp"

#define UP_INPUT 265
#define DOWN_INPUT 264
#define LEFT_INPUT 263
#define RIGHT_INPUT 262
#define Z_INPUT 88
#define X_INPUT 90
#define W_INPUT 87
#define A_INPUT 65
#define S_INPUT 83
#define D_INPUT 68

using namespace std;