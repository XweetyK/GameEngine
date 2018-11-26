#include "CollisionManager.h"
#include <math.h>


CollisionManager::CollisionManager(int layers) {
	for (int i = 0; i < layers; i++)
	{
		_layers.push_back(new list<BoxCollider*>());
	}
	_colliding = false;

}
CollisionManager::~CollisionManager(){
}

void CollisionManager::AddEntity(BoxCollider* _box, int layer) {
	_layers[layer]->push_back(_box);
}

void CollisionManager::UpdateCollider() {
	for (int i = 0; i < _layers.size(); i++)
	{
		for (int j = i + 1; j < _layers.size(); j++)
		{
			CheckCollisions(_layers[i], _layers[j]);
		}
	}
}
void CollisionManager::CheckCollisions(list<BoxCollider*> *layer1, list<BoxCollider*> *layer2) {
	for (list<BoxCollider*>::iterator box1 = layer1->begin(); box1 != layer1->end(); box1++) {
		for (list<BoxCollider*>::iterator box2 = layer2->begin(); box2 != layer2->end(); box2++) {
			Collision(*box1, *box2);
		}
	}
}

void CollisionManager::Collision(BoxCollider* box1, BoxCollider* box2) {
	glm::vec2 Diff = (box1->GetEntity()->GetFullPos() - box2->GetEntity()->GetFullPos());
	glm::vec2 module = abs(Diff);
	if (module.x <= (box1->GetWidthBase() + box2->GetWidthBase()) / 2.0f && module.y <=
		(box1->GetHeightBase() + box2->GetHeightBase()) / 2.0f) {
		float xP = ((box1->GetWidthBase() / 2.0f) + (box2->GetWidthBase() / 2.0f)) - module.x;
		float yP = ((box1->GetHeightBase() / 2.0f) + (box2->GetHeightBase() / 2.0f)) - module.y;
		if (xP > yP) {
			if (Diff.y > 0) {
				yP = -yP;
			}
			if (box1->GetMass() > box2->GetMass()) {
				box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX(), box1->GetEntity()->GetPosY() + (yP / 2.0f), box1->GetEntity()->GetPosZ());
				box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX(), box2->GetEntity()->GetPosY() - (yP / 2.0f), box2->GetEntity()->GetPosZ());
				_colliding = true;
			}
			if (box1->GetMass() < box2->GetMass()) {
				box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX(), box1->GetEntity()->GetPosY() - (yP / 2.0f), box1->GetEntity()->GetPosZ());
				box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX(), box2->GetEntity()->GetPosY() + (yP / 2.0f), box2->GetEntity()->GetPosZ());
				_colliding = true;
			}
			if (box1->GetMass() == box2->GetMass()) {
				box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX(), box1->GetEntity()->GetPosY(), box1->GetEntity()->GetPosZ());
				box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX(), box2->GetEntity()->GetPosY(), box2->GetEntity()->GetPosZ());
				_colliding = true;
			}
		}
		else {
			if (Diff.x > 0) {
				xP = -xP;
			}
			if (box1->GetMass() > box2->GetMass()) {
				box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX() + (xP / 2.0f), box1->GetEntity()->GetPosY(), box1->GetEntity()->GetPosZ());
				box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX() - (xP / 2.0f), box2->GetEntity()->GetPosY(), box2->GetEntity()->GetPosZ());
				_colliding = true;
			}
			if (box1->GetMass() < box2->GetMass()) {
				box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX() - (xP / 2.0f), box1->GetEntity()->GetPosY(), box1->GetEntity()->GetPosZ());
				box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX() + (xP / 2.0f), box2->GetEntity()->GetPosY(), box2->GetEntity()->GetPosZ());
				_colliding = true;
			}
			if (box1->GetMass() == box2->GetMass()) {
				box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX(), box1->GetEntity()->GetPosY(), box1->GetEntity()->GetPosZ());
				box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX(), box2->GetEntity()->GetPosY(), box2->GetEntity()->GetPosZ());
				_colliding = true;
			}
		}
	}
	else {
		_colliding = false;
	}
}