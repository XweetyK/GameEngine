#pragma once
#include "Exports.h"
#include "Include.h"
#include "Sprite.h"
#include <ctype.h>
using namespace std;
struct TileProperty {
	int _tilenum;
	float* _uvVertex;
};
class ENGINEDLL_API TilemapManager
{
private:
	char _reader[200] = "";

	int** _tilemap;
	ifstream _tilesetFile;

	float* _meshVertex;
	float* _uvVertex;

	int _width;
	int _height;
	int _tileW;
	int _tileH;
	int _tileRow;
	int _tileCol;
	int _tilesCant;
	bool _readingTile;
	int _spriteVertexCant;
	int _uvVertexCant;

	Sprite* _mesh;
	Material* _mat;
	Frame* _frames;
	TileProperty* _properties;

public:
	TilemapManager(int width, int height, int tileSizeW, int tileSizeH, int tilesTypeCant, Renderer* renderer);
	~TilemapManager();
	void SetTilemap(const char* FILE);
	void SetSprite(const char * BMPfile, int texWidth, int texHeight);
	void SetTilesetProperty(int tileNum, int tileSprite);
	void CreateTiles();
	void CreateUV(int textureWidth, int textureHeight);
	void Draw();
	void SetPos(float x, float y, float z);
	float GetPos(int axis);
};

