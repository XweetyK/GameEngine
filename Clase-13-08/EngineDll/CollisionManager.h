#pragma once
#include "Exports.h"
#include "Externals.h"
#include "BoxCollider.h"
#include "Entity.h"
#include <vector>
#include <list>
using namespace std;

class ENGINEDLL_API CollisionManager
{
private:
	vector<list<BoxCollider*>*> _layers;
	bool _colliding; //test para animaciones
public:
	CollisionManager(int layers);
	~CollisionManager();
	void AddEntity(BoxCollider* _box, int layer);
	void CheckLayers();
	void CheckCollisions(list<BoxCollider*> *layer1, list<BoxCollider*> *layer2);
	void Collision(BoxCollider* box1, BoxCollider* box2);
	bool IsColliding() { return _colliding; };
};

