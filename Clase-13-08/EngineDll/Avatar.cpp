#include "Avatar.h"

Avatar::Avatar(Renderer* renderer){
	_sprite = new Sprite(renderer);
	_animator = new Animator(_sprite);
	_boxCollider = new BoxCollider();
	_boxCollider->AttachEntity(_sprite);
	_material = Material::LoadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRG_SHADER_PATH);
}

Avatar::~Avatar(){
	//delete _sprite;
	delete _animator;
	delete _boxCollider;
}

void Avatar::SetSprite(const char* BMPfile) {
	_sprite->LoadBMP(BMPfile);
	_sprite->SetMaterial(_material);
}
void Avatar::DrawSprite() {
	_sprite->Draw();
}
void Avatar::SetSpritePos(float posX, float posY, float posZ) {
	_sprite->SetPos(posX, posY, posZ);
}
void Avatar::SetSpriteRot(float rotX, float rotY, float rotZ) {
	_sprite->SetRot(rotX, rotY, rotZ);
}
void Avatar::SetSpriteScale(float scaleX, float scaleY, float scaleZ) {
	_sprite->SetScale(scaleX, scaleY, scaleZ);
}
void Avatar::SetAnimator(int frameW, int frameH, int textureW, int textureH, int* frames, int framesCant, double speed) {
	_sprite->MakeFrames(frameW, frameH, textureW, textureH);
	_sprite->SetFrame(1);
	_animator->SetAnimation(frames, framesCant, speed);
}
void Avatar::SetAnimator(int frameW, int frameH, int textureW, int textureH, int frame) {
	_sprite->MakeFrames(frameW, frameH, textureW, textureH);
	_sprite->SetFrame(frame);
}
void Avatar::SetAnimatorFrames(int* frames, int framesCant, double speed) {
	_animator->SetAnimation(frames, framesCant, speed);
}
void Avatar::SetBoxCollider(float width, float height, float mass, float offsetX, float offsetY, bool staticness) {
	_boxCollider->SetBoxLimits(width, height, mass, offsetX, offsetY, staticness);
}
void Avatar::UpdateAvatar(double deltatime, bool animated) {
	if (animated) {
		_animator->Update(deltatime);
	}
	_boxCollider->UpdateBox();
}
