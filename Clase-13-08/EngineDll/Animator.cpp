#include "Animator.h"

Animator::Animator(Sprite* sprite) {
	_sprite = sprite;
	_stop = false;
	_timer = 0;
	_cont = _firstFrame = _lastFrame = 0;
	_frames = NULL;
}

Animator::~Animator(){
	delete _sprite;
}

//void Animator::SetAnimation(int firstFrame, int lastFrame, double speed) {
//	int framesCant = lastFrame - firstFrame;
//	_actualFrame = _firstFrame = firstFrame;
//	_lastFrame = lastFrame;
//	_speed = speed;
//	if (_frames != NULL) {
//		delete _frames;
//		_frames = NULL;
//	}
//	_frames = new int[framesCant];
//	for (int i = 0; i < framesCant; i++){
//		_frames[i] = firstFrame + i;
//	}
//}
void Animator::SetAnimation(int* frames, int framesCant, double speed) {
	_frames = frames;
	_framesCant = framesCant;
	_cont = 0;
	_firstFrame = _frames[0];
	_lastFrame = _frames[_framesCant];
	_speed = speed;
}

void Animator::Update(double deltaTime) {
	if (!_stop && _sprite != NULL && _frames != NULL) {
		_timer += deltaTime*_speed;
		if (_timer >= 1) {
			_timer = 0;
			if (_cont == _framesCant) {
				_cont = 0;
			}
			_sprite->SetFrame(_frames[_cont]);
			_cont++;
		}
	}
}

void Animator::PlayAnimation() {
	_stop = false;
}

void Animator::StopAnimation() {
	_stop = true;
}