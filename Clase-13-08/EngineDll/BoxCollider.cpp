#include "BoxCollider.h"



BoxCollider::BoxCollider(){
	_updHUp = 0.0f;
	_updWRgt = 0.0f;
	_updHDw = 0.0f;
	_updWLft = 0.0f;

	_entity = NULL;

	_width = 0.0f;
	_height = 0.0f;
	_mass = 0.0f;
	_offsetX = 0.0f;
	_offsetY = 0.0f;
}

BoxCollider::~BoxCollider(){
}

void BoxCollider::AttachEntity(Entity* entity) {
	_entity = entity;
}

void BoxCollider::SetBoxLimits(float width, float height, float mass, float offsetX, float offsetY) {
	_width = width;
	_height = height;
	_mass = mass;
	_offsetX = offsetX;
	_offsetY = offsetY;
}
void BoxCollider::UpdateBox() {
	float x = _entity->GetPosX();
	float y = _entity->GetPosY();

	_updHUp = y + _height + _offsetY;
	_updHDw = y - _height + _offsetY;

	_updWLft= x - _width + _offsetX;
	_updWRgt= x + _width + _offsetX;
}
