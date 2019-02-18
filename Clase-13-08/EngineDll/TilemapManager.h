#pragma once
#include "Exports.h"
#include "Include.h"
#include "Tile.h"
#include <ctype.h>
using namespace std;
struct TileProperty {
	bool _collide;
	bool _animated;
	const char* BMPsprite;
	int* _frames;
	int _texW;
	int _texH;
	int _framesCant;
	double _speed;
	int _staticFrame;
};
class ENGINEDLL_API TilemapManager
{
private:
	char _reader[200] = "";

	int** _tilemap;
	Tile** _tilesGroup;
	ifstream _tilesetFile;

	int _width;
	int _height;
	int _tileW;
	int _tileH;
	int _tileRow;
	int _tileCol;
	bool _readingTile;
	float _scaleFactor;

	TileProperty* _properties;
public:
	TilemapManager(int width, int height, int tileSizeW, int tileSizeH, int tilesTypeCant, float scaleFactor);
	~TilemapManager();
	void SetTilemap(const char* FILE);
	void SetTilesetProperty(int tileSet, bool collision, const char* BMP, bool animated, int textureW, int textureH, int* frames, int framesCant, double speed);
	void SetTilesetProperty(int tileSet, bool collision, const char* BMP, bool animated, int textureW, int textureH, int staticFrame);
	void CreateTiles(Renderer* renderer);
	void Draw();
	void Update(double deltaTime);
};

