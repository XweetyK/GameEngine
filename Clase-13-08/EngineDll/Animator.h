#pragma once
#include"Exports.h"
#include "Externals.h"
#include "Sprite.h"
class ENGINEDLL_API Animator
{
private:
	bool _stop;
protected:
	Sprite* _sprite;
	double _speed;
	double _timer;
	int _firstFrame;
	int _lastFrame;
	int _framesCant;
	int _cont;
	int* _frames;
public:
	Animator(Sprite* sprite);
	//void SetAnimation(int firstFrame, int lastFrame, double speed);
	void SetAnimation(int* frames, int framesCant, double speed);
	void Update(double deltaTime);
	void PlayAnimation();
	void StopAnimation();
	~Animator();
	int* GetFrames() { return _frames; }
};

