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
float CollisionManager::CheckMass(float mass1, float mass2, int whichMass) {
	float totalMass;
	float mass1Percent;
	float mass2Percent;

	totalMass = mass1 + mass2;
	mass1Percent = (mass2 / totalMass) ;
	mass2Percent = (mass1 / totalMass) ;

	switch (whichMass){
	case 1:
		return mass1Percent;
		break;
	case 2:
		return mass2Percent;
		break;
	}
}

void CollisionManager::Collision(BoxCollider* box1, BoxCollider* box2) {

	glm::vec2 Diff = (box1->GetEntity()->GetFullPos() - box2->GetEntity()->GetFullPos());
	glm::vec2 deltaPos = abs(Diff);

	if (deltaPos.x <= (box1->GetWidthBase() + box2->GetWidthBase()) / 2.0f && deltaPos.y <=
		(box1->GetHeightBase() + box2->GetHeightBase()) / 2.0f) {

		float pX = ((box1->GetWidthBase() / 2.0f) + (box2->GetWidthBase() / 2.0f)) - deltaPos.x;
		float pY = ((box1->GetHeightBase() / 2.0f) + (box2->GetHeightBase() / 2.0f)) - deltaPos.y;

		float mass1P = CheckMass(box1->GetMass(), box2->GetMass(), 1);
		float mass2P = CheckMass(box1->GetMass(), box2->GetMass(), 2);

		//cout << mass1P << " , " << mass2P<<endl;

		if (pX > pY) {
			if (Diff.y > 0) {
				pY = -pY;
			}
			if (!box1->IsStatic() && !box2->IsStatic()) {
				if (mass1P != mass2P) {
					box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX(), box1->GetEntity()->GetPosY() - (pX*mass1P), box1->GetEntity()->GetPosZ());
					box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX(), box2->GetEntity()->GetPosY() + (pX*mass2P), box2->GetEntity()->GetPosZ());
					_colliding = true;
				}
				if (mass1P == mass2P) {
					_colliding = true;
				}
			}
			if (box1->IsStatic()) {
				box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX(), box2->GetEntity()->GetPosY() + (pY), box2->GetEntity()->GetPosZ());	
				_colliding = true;
			}
			if (box2->IsStatic()) {
				box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX(), box2->GetEntity()->GetPosY() + (pY), box2->GetEntity()->GetPosZ());
				_colliding = true;
			}
		}
		else {
			if (Diff.x > 0) {
				pX = -pX;
			}
			if (!box1->IsStatic() && !box2->IsStatic()) {
				if (mass1P != mass2P) {
					box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX() - (pX*mass1P), box1->GetEntity()->GetPosY(), box1->GetEntity()->GetPosZ());
					box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX() + (pX*mass2P), box2->GetEntity()->GetPosY(), box2->GetEntity()->GetPosZ());
					_colliding = true;
				}
				if (mass1P == mass2P) {
					_colliding = true;
				}
			}
			if(box1->IsStatic()) {
				box2->GetEntity()->SetPos(box2->GetEntity()->GetPosX() + (pX), box2->GetEntity()->GetPosY(), box2->GetEntity()->GetPosZ());
				_colliding = true;
			}
			if (box2->IsStatic()) {
				box1->GetEntity()->SetPos(box1->GetEntity()->GetPosX() + (pX), box1->GetEntity()->GetPosY(), box1->GetEntity()->GetPosZ());
				_colliding = true;
			}
		}
	}
	else {
		box1->GetEntity()->CanMove(true);
		box2->GetEntity()->CanMove(true);
		_colliding = false;
	}
}