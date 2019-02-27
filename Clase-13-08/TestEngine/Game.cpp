#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}
bool Game::onStart() {

	_collisionManager = new CollisionManager(2);

	_mapLimitX = 0;
	_mapLimitY = 0;

	_winner = false;

	_mapX = 10;
	_mapY = 30;

	renderer->CameraPos(_mapX, _mapY);

	_x = 6;
	_y = 5;
	_lastPosX = 11;
	_lastPosY = 30;

	_timer = 0;
	_gemCont = 0;
	_gameTime = -2;

	_tilemap = new TilemapManager(1024,640,32,32,5,renderer);
	_tilemap->SetTilemap(TILEMAP_PATH);

	_tilemap->SetTilesetProperty(0, 1, true);
	_tilemap->SetTilesetProperty(1, 1, false);
	_tilemap->SetTilesetProperty(2, 2, true);
	_tilemap->SetTilesetProperty(3, 3, true);
	_tilemap->SetTilesetProperty(4, 4, true);
	
	_tilemap->SetSprite(TILESET_PATH, 96, 128);
	_tilemap->SetPos(-2.0f, 38.0f, -1.0f);
	_tilemap->SetScale(2.0f, 2.0f, 0.0f);

	_player = new Player(renderer);
	_player->_player->SetSpriteScale(2.0f, 2.0f, 0.0f);
	_player->SetPos(11.0f, 30.0f, 0.0f);

	_gem = new Avatar(renderer);
	_gem->SetSprite(GEM_PATH);
	_gem->SetAnimator(36, 36, 108, 36, 0);
	_gem->SetSpriteScale(1, 1, 1);
	_gem->SetBoxCollider(1.5f, 1.5f, 1.0f, 0, 0, false);
	_gem->SetSpritePos(3.0f, 25.0f, 0.5f);

	_collisionManager->AddEntity(_gem->GetBoxCollider(), 1);
	_collisionManager->AddEntity(_player->_player->GetBoxCollider(), 0);

	_winnerScreen = new Sprite(renderer);
	_winnerScreen->LoadBMP(WIN_PATH);
	_mat = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
	_winnerScreen->SetMaterial(_mat);
	_winnerScreen->SetPos(0, 0, 2.0f);
	_winnerScreen->SetScale(20, 20, 0);

	_loserScreen = new Sprite(renderer);
	_loserScreen->LoadBMP(LOSE_PATH);
	_loserScreen->SetMaterial(_mat);
	_loserScreen->SetPos(0, 0, 3.0f);
	_loserScreen->SetScale(20, 20, 0);

	_tutorial = new Sprite(renderer);
	_tutorial->LoadBMP(TUTO_PATH);
	_tutorial->SetMaterial(_mat);
	_tutorial->SetPos(0, 0, 2.0f);
	_tutorial->SetScale(20, 20, 0);

	_red = new Sprite(renderer);
	_red->LoadBMP(RED_PATH);
	_red->SetMaterial(_mat);
	_red->SetPos(0, 0, 2.0f);
	_red->SetScale(20, 20, 0);

	_red2 = new Sprite(renderer);
	_red2->LoadBMP(RED_PATH);
	_red2->SetMaterial(_mat);
	_red2->SetPos(0, 0, 2.2f);
	_red2->SetScale(20, 20, 0);


	std::cout << "game::start()" << endl;
	_i = 0;
	return true;
}

bool Game::onStop() {
	std::cout << "game::stop()" << endl;
	return true;
}
bool Game::onUpdate(double deltaTime) {
	std::cout << "game::onUpdate()";
	_i++;
	std::cout <<_i<< endl;

	_gameTime += deltaTime;
	_timer += 1 * deltaTime;

	if (_winner == false) {
		Input(deltaTime);
	}

	_collisionManager->UpdateCollider();
	_player->Update(deltaTime);
	renderer->CameraPos(_mapX, _mapY);
	AdjustUIPos();
	GemMovement();
	
	if (_gemCont == 6) {
		_winner = true;
	}
	
	if (_i > 5) {
		return false;
	}
	return true;
}
void Game::Camera(int x, int y) {
	_tilemap->SetPos(_tilemap->GetPos(1) + x, _tilemap->GetPos(2) + y, -1.0f);
	_gem->SetSpritePos(_gem->GetPosX() + x, _gem->GetPosY() + y, 0.5f);
}
void Game::onDraw() {
	_tilemap->Draw();
	_player->Draw();
	_gem->DrawSprite();
	CheckWinner();
}

void Game::Input(double deltaTime) {
	if (input(UP_INPUT)) {
		if (_tilemap->GetCollision(_tilemap->GetTile(_y - 1, _x)) == false) {
			_player->Movement("up", 0, MOV_POS*deltaTime);
			if (_player->_player->GetPosY() > _lastPosY + 2) {
				_lastPosY += 2;
				_mapY += 2;
				_y--;
			}
		}
	}
	else if (input(DOWN_INPUT) && _timer > 0.1) {
		if (_tilemap->GetCollision(_tilemap->GetTile(_y + 1, _x)) == false) {
			_player->Movement("down", 0, -MOV_POS*deltaTime);
			if (_player->_player->GetPosY() < _lastPosY - 2) {
				_lastPosY -= 2;
				_mapY -= 2;
				_y++;
			}
		}
	}
	else if (input(LEFT_INPUT) && _timer > 0.1) {
		if (_tilemap->GetCollision(_tilemap->GetTile(_y, _x - 1)) == false) {
			_player->Movement("left", -MOV_POS*deltaTime, 0);
			if (_player->_player->GetPosX() < _lastPosX - 2) {
				_lastPosX -= 2;
				_mapX -= 2;
				_x--;
			}
		}
	}
	else if (input(RIGHT_INPUT) && _timer > 0.1) {
		if (_tilemap->GetCollision(_tilemap->GetTile(_y, _x + 1)) == false) {
			_player->Movement("right", MOV_POS*deltaTime, 0);
			if (_player->_player->GetPosX() > _lastPosX + 2) {
				_lastPosX += 2;
				_mapX += 2;
				_x++;
			}
		}
	}
	else {
		_player->Movement("still", 0, 0);
	}
}

void Game::CheckWinner() {
	if (_winner == true) {
		_winnerScreen->Draw();
	}
	if (_winner == false) {
		if (_gameTime < 0) {
			_tutorial->Draw();
		}
		if (_gameTime > 20.0f) {
			_red->Draw();
		}
		if (_gameTime > 30.0f) {
			_red2->Draw();
		}
		if (_gameTime > 40.0f) {
			_loserScreen->Draw();
		}
	}
}

void Game::GemMovement() {
	if (_collisionManager->IsColliding()) {
		switch (_gemCont)
		{
		case 0:
			_gem->SetSpritePos(11.0f, 5.0f, 0.5f);
			_gemCont++;
			break;
		case 1:
			_gem->SetSpritePos(35.0f, 17.0f, 0.5f);
			_gem->GetSprite()->SetFrame(2);
			_gemCont++;
			break;
		case 2:
			_gem->SetSpritePos(53.0f, 3.0f, 0.5f);
			_gem->GetSprite()->SetFrame(2);
			_gemCont++;
			break;
		case 3:
			_gem->SetSpritePos(49.0f, 17.0f, 0.5f);
			_gem->GetSprite()->SetFrame(0);
			_gemCont++;
			break;
		case 4:
			_gem->SetSpritePos(5.0f, 15.0f, 0.5f);
			_gem->GetSprite()->SetFrame(1);
			_gem->SetSpriteScale(2, 2, 0);
			_gemCont++;
			break;
		case 5:
			_gem->SetSpritePos(-44.0f, -44.0f, 0.5f);
			_gemCont++;
			break;
		}
	}
}

void Game::AdjustUIPos() {
	_red->SetPos(_mapX, _mapY, _red->GetPosZ());
	_red2->SetPos(_mapX, _mapY, _red2->GetPosZ());
	_winnerScreen->SetPos(_mapX, _mapY, _winnerScreen->GetPosZ());
	_loserScreen->SetPos(_mapX, _mapY, _loserScreen->GetPosZ());
	_tutorial->SetPos(_mapX, _mapY, _tutorial->GetPosZ());
}