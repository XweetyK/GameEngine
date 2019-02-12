#include "Tile.h"

Tile::Tile() {

}

void Tile::SetTileProperty(Renderer* renderer, int w, int h, const char* BMPtile, int type, bool collide){
	_sprite = new Avatar(renderer);
	_sprite->SetSprite(BMPtile);
	_empty = false;
	_tileType = type;
	_enabled = true;
	_collide = collide;
	_width = w;
	_height = h;
}

Tile::~Tile(){
	if (_sprite) {
		delete _sprite;
	}
}

void Tile::DrawTile() {
	_sprite->DrawSprite();
}
void Tile::SetTilePos(float posX, float posY, float posZ) {
	_sprite->SetSpritePos(posX, posY, posZ);
}
void Tile::SetTileScale(float scaleX, float scaleY, float scaleZ) {
	_sprite->SetSpriteScale(scaleX, scaleY, scaleZ);
}
void Tile::SetAnimator(int frameW, int frameH, int textureW, int textureH, int* frames, int framesCant, double speed) {
	_sprite->SetAnimator(frameW, frameH, textureW, textureH, frames, framesCant, speed);
}
void Tile::SetAnimator(int frameW, int frameH, int textureW, int textureH, int frame) {
	_sprite->SetAnimator(frameW, frameH, textureW, textureH, frame);
}
void Tile::SetBoxCollider(float width, float height, float mass, float offsetX, float offsetY, bool staticness) {
	//_sprite->SetBoxCollider()
}
void Tile::UpdateAnim(double deltatime, bool animated) {
	_sprite->UpdateAvatar(deltatime, animated);
}
