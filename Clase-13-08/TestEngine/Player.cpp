#include "Player.h"

Player::Player(Renderer* rend){
	_player = new Avatar(rend);
	_player->SetSprite(CRASH_SPRITE_PATH);
	_player->SetSpriteScale(1, 1, 1);	

	_facingUp = new int[4]{
		10, 11, 12, 13
	};
	_facingDw = new int[4]{
		14, 15, 16, 17
	};
	_facingLf = new int[4]{
		5, 6, 7, 8
	};
	_facingRt = new int[4]{
		1, 2, 3, 4
	};
	_still = new int[1]{
		0
	};

	_player->SetAnimator(32, 32, 128, 160, _facingRt, 4, 8);

	_player->SetBoxCollider(1, 1, 5, 0, -0.3, false);
}


Player::~Player(){
	delete _player;
}

void Player::Update(double deltaTime) {
	_player->UpdateAvatar(deltaTime,true);
}

void Player::Draw() {
	_player->DrawSprite();
}
void Player::SetPos(float x, float y, float z) {
	_player->SetSpritePos(x, y, z);
}

void Player::Movement(const char* facing, float x, float y){
	_player->SetSpritePos(_player->GetPosX()+x, _player->GetPosY() + y, 0.0f);
	if (facing == "up") {
		if(_player->GetFrames() != _facingUp)
		_player->SetAnimatorFrames(_facingUp, 4, 8);
	}
	if (facing == "down") {
		if (_player->GetFrames() != _facingDw)
		_player->SetAnimatorFrames(_facingDw, 4, 8);
	}
	if (facing == "left") {
		if (_player->GetFrames() != _facingLf)
		_player->SetAnimatorFrames(_facingLf, 4, 8);
	}
	if (facing == "right") {
		if (_player->GetFrames() != _facingRt)
		_player->SetAnimatorFrames(_facingRt, 4, 8);
	}
	if (facing == "still") {
		_player->SetAnimatorFrames(_still, 1, 8);
	}
}

