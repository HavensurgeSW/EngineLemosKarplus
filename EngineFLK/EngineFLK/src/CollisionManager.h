#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "Exports.h"

class Entity2D;

class FLK_API CollisionManager
{
private:

public:
	bool CheckCollision(const Entity2D* one, const Entity2D* two);
};

#endif