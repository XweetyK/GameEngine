#include "TilemapManager.h"
#include "Renderer.h"



TilemapManager::TilemapManager(int width, int height, int tileSizeW, int tileSizeH, int tilesTypeCant, float scaleFactor) {
	_width = width;
	_height = height;
	_tileW = tileSizeW;
	_tileH = tileSizeH;
	_scaleFactor = scaleFactor;

	_tileCol = _width / _tileW;
	_tileRow = _height / _tileH;

	_tilemap = new int*[_tileRow];
	for (int i = 0; i < _tileRow; i++){
		_tilemap[i] = new int[_tileCol];
	}

	_properties = new TileProperty[tilesTypeCant];
}


TilemapManager::~TilemapManager() {
	cout << "~tilemap" << endl;
	/*if (_tilemap) {
	for (int i = 0; i < _height; i++) {
		delete[] _tilemap[i];
	}
	delete[] _tilemap;
	}
	if (_tilesGroup) {
		for (int i = 0; i < _height; i++) {
			delete[] _tilesGroup[i];
		}
		delete[] _tilesGroup;
	}*/
}

void TilemapManager::SetTilemap(const char* FILE) {
	cout << _tileRow << " , " << _tileCol << endl;
	int temp=0;
	_tilesetFile.open(FILE);
	int j = 0;
	while (!_tilesetFile.eof()) {
		_tilesetFile.getline(_reader, 200);
		if (_reader[0] == '-' || isdigit(_reader[0])) {
			_readingTile = true;
			cout << "number!" << endl;
		}
		else { _readingTile = false; }
		if (_readingTile == true) {
			int i = 0;
			int k = 0;
			while (_reader[i] != 0) {
				if (_reader[i] != ',') {
					if (_reader[i] == '-') {
						_tilemap[j][k] = -1;
						i = i + 2;
						k++;
					}
					else {
						_tilemap[j][k] = (_reader[i] - '0');
						i++;
						k++;
					}
				}
				else {
					i++;
				}
			}
			j++;
		}
	}
	_tilesetFile.close();
}
void TilemapManager::SetTilesetProperty(int tileSet, bool collision, const char* BMP, bool animated, int textureW, int textureH, int* frames, int framesCant, double speed){
	_properties[tileSet].BMPsprite = BMP;
	_properties[tileSet]._collide = collision;
	_properties[tileSet]._animated = animated;
	_properties[tileSet]._frames = frames;
	_properties[tileSet]._framesCant = framesCant;
	_properties[tileSet]._texW = textureW;
	_properties[tileSet]._texH = textureH;
	_properties[tileSet]._speed = speed;
}
void TilemapManager::SetTilesetProperty(int tileSet, bool collision, const char* BMP, bool animated, int textureW, int textureH, int staticFrame) {
	_properties[tileSet].BMPsprite = BMP;
	_properties[tileSet]._collide = collision;
	_properties[tileSet]._animated = animated;
	_properties[tileSet]._staticFrame = staticFrame;
	_properties[tileSet]._texW = textureW;
	_properties[tileSet]._texH = textureH;
	_properties[tileSet]._speed = 0.0f;
}
void TilemapManager::CreateTiles(Renderer* renderer) {
	_tilesGroup = new Tile*[_tileRow];
	for (int i = 0; i < _tileRow; i++) {
		_tilesGroup[i] = new Tile[_tileCol];
	}

	for (int i = 0; i < _tileRow; i++){
		for (int j = 0; j < _tileCol; j++) {
			if (_tilemap[i][j] != -1) {
				_tilesGroup[i][j].SetEmpty(false);
				_tilesGroup[i][j].SetTileProperty(renderer, _tileW, _tileH, _properties[_tilemap[i][j]].BMPsprite, _tilemap[i][j], _properties[_tilemap[i][j]]._collide);
				_tilesGroup[i][j].SetTilePos((j*_scaleFactor) - (10.0f-(_scaleFactor/2)), (i*-_scaleFactor) + (10.0f - (_scaleFactor / 2)), 0.0f);
				_tilesGroup[i][j].SetTileScale(_scaleFactor, _scaleFactor, 0);
				if (_properties[_tilemap[i][j]]._animated == true) {
				_tilesGroup[i][j].SetAnimator(_tileW, _tileH, _properties[_tilemap[i][j]]._texW,
					_properties[_tilemap[i][j]]._texH, _properties[_tilemap[i][j]]._frames,
					_properties[_tilemap[i][j]]._framesCant, _properties[_tilemap[i][j]]._speed);
				}
				if (_properties[_tilemap[i][j]]._animated == false) {
					_tilesGroup[i][j].SetAnimator(_tileW, _tileH, _properties[_tilemap[i][j]]._texW,
						_properties[_tilemap[i][j]]._texH, _properties[_tilemap[i][j]]._staticFrame);
				}
			}
			else {
				_tilesGroup[i][j].SetEmpty(true);
			}
		}
		cout << endl;
	}
}
void TilemapManager::Draw() {
	for (int i = 0; i < _tileRow; i++) {
		for (int j = 0; j < _tileCol; j++) {
			if (_tilesGroup[i][j].GetEmpty() != true) {
				_tilesGroup[i][j].DrawTile();
			}
		}
	}
}
void TilemapManager::Update(double deltaTime) {
	for (int i = 0; i < _tileRow; i++) {
		for (int j = 0; j < _tileCol; j++) {
			if (_tilesGroup[i][j].GetEmpty() != true) {
				_tilesGroup[i][j].UpdateAnim(deltaTime, _properties[_tilesGroup[i][j].GetType()]._animated);
			}
		}
	}
}