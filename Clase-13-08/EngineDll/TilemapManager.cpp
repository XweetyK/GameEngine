#include "TilemapManager.h"
#include "Renderer.h"



TilemapManager::TilemapManager(int width, int height, int tileSizeW, int tileSizeH, int tilesTypeCant, Renderer* renderer) {
	_width = width;
	_height = height;
	_tileW = tileSizeW;
	_tileH = tileSizeH;
	_tilesCant = tilesTypeCant;

	_tileCol = _width / _tileW;
	_tileRow = _height / _tileH;

	_spriteVertexCant = _tileCol*_tileRow * 4 * 3;
	_uvVertexCant = _tileCol*_tileRow * 4 * 2;

	_tilemap = new int*[_tileRow];
	for (int i = 0; i < _tileRow; i++){
		_tilemap[i] = new int[_tileCol];
	}

	_properties = new TileProperty[tilesTypeCant];
	_mesh = new Sprite(renderer);
	_mat= Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);

	_meshVertex = new float[_spriteVertexCant];
	_uvVertex = new float[_uvVertexCant];
}


TilemapManager::~TilemapManager() {
	cout << "~tilemap" << endl;
	if (_tilemap) {
		for (int i = 0; i < _tileRow; i++) {
			delete[] _tilemap[i];
		}
		delete[] _tilemap;
	}
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

void TilemapManager::SetSprite(const char * BMPfile, int texWidth, int texHeight) {
	_mesh->LoadBMP(BMPfile);
	CreateTiles();
	CreateUV(texWidth,texHeight);
	_mesh->SetVertex(_meshVertex, (_spriteVertexCant / 3));
	_mesh->SetUvVertex(_uvVertex, (_uvVertexCant / 2));
	_mesh->SetMaterial(_mat);
}

void TilemapManager::SetTilesetProperty(int tileNum, int tileSprite, bool collide) {
	_properties[tileNum]._tilenum = tileSprite;
	_properties[tileNum]._collide = collide;
}

void TilemapManager::CreateTiles() {
	float _X = 0.0f;
	float _Y = 0.0f;
	float _Z = 0.0f;
	bool _looping = false;
	bool _up = true;
	int _cont = 0;
	int xcont = 2;
	for (int j = 0; j < _tileRow; j++) {
		switch (_looping)
		{
		case true:
			for (int i = 0; i < (_tileCol*4); i++) {
				_meshVertex[_cont] = _X;
				_meshVertex[_cont + 1] = _Y;
				_meshVertex[_cont + 2] = _Z;
				xcont++;
				if (xcont == 4) {
					_X -= 1.0f;
					xcont = 0;
				}
				if (_up) {
					_Y += 1.0;
					_up = false;
				}
				else {
					_Y -= 1.0;
					_up = true;
				}
				_cont += 3;
			}
			_Y -= 1;
			_looping = false;
			break;
		case false:
			for (int i = 0; i < (_tileCol * 4); i++) {
				_meshVertex[_cont] = _X;
				_meshVertex[_cont + 1] = _Y;
				_meshVertex[_cont + 2] = _Z;
				xcont++;
				if (xcont == 4) {
					_X += 1.0f;
					xcont = 0;
				}
				if (_up) {
					_Y += 1.0;
					_up = false;
				}
				else {
					_Y -= 1.0;
					_up = true;
				}
				_cont += 3;
			}
			cout << _cont << endl;
			_Y -= 1;
			_looping = true;
			break;
		}
	}
}

void TilemapManager::CreateUV(int textureWidth, int textureHeight) {
	int columns = textureHeight / _tileH;
	int rows = textureWidth / _tileW;
	float uvHeight = (float)_tileH / (float)textureHeight;
	float uvWidth = (float)_tileW / (float)textureWidth;
	int framesCant = rows * columns;
	int cont = 0;

	_frames = new Frame[framesCant];
	for (int j = 0; j < columns; j++) {
		for (int i = 0; i < rows; i++) {
			_frames[cont].SetVertex(uvWidth*i, uvWidth*(i + 1), 1.0f - (uvHeight*j), 1.0f - (uvHeight*(j + 1)));
			if (cont != framesCant) {
				cont++;
			}
		}
	}

	for (int i = 0; i < _tilesCant; i++){
		_properties[i]._uvVertex = _frames[_properties[i]._tilenum].GetFrame();
	}

	bool _flipRow = false;

	int _cont = 0;
	for (int i = 0; i < _tileRow; i++) {
		if (_flipRow) {
			for (int j = _tileCol-1; j > -1; j--) {
				if (_tilemap[i][j] == -1) {
					for (int k = 0; k < 8; k++)
					{
						_uvVertex[_cont + k] = _frames[0].GetFrame()[k];
					}
					_cont += 8;
				}
				else {
					_uvVertex[_cont] = _properties[_tilemap[i][j]]._uvVertex[4];
					_uvVertex[_cont + 1] = _properties[_tilemap[i][j]]._uvVertex[5];
					_uvVertex[_cont + 2] = _properties[_tilemap[i][j]]._uvVertex[6];
					_uvVertex[_cont + 3] = _properties[_tilemap[i][j]]._uvVertex[7];
					_uvVertex[_cont + 4] = _properties[_tilemap[i][j]]._uvVertex[0];
					_uvVertex[_cont + 5] = _properties[_tilemap[i][j]]._uvVertex[1];
					_uvVertex[_cont + 6] = _properties[_tilemap[i][j]]._uvVertex[2];
					_uvVertex[_cont + 7] = _properties[_tilemap[i][j]]._uvVertex[3];
					_cont += 8;
				}
			}
			_flipRow = false;
		}
		else {
			for (int j = 0; j < _tileCol; j++) {
				for (int k = 0; k < 8; k++) {
					if (_tilemap[i][j] == -1) {
						_uvVertex[_cont + k] = _frames[0].GetFrame()[k];
					}
					else {
						_uvVertex[_cont + k] = _properties[_tilemap[i][j]]._uvVertex[k];
					}
				}
				_cont += 8;
			}
			_flipRow = true;
		}
	}
}

void TilemapManager::Draw() {
	_mesh->Draw();
}

void TilemapManager::SetPos(float x, float y, float z) {
	_mesh->SetPos(x, y, z);
}

float TilemapManager::GetPos(int axis) {
	switch (axis)
	{
	case 1:
		return _mesh->GetPosX();
		break;
	case 2:
		return _mesh->GetPosY();
		break;
	case 3:
		return _mesh->GetPosZ();
		break;
	}
}