#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "Exports.h"
#include "Entity2D.h"

class FLK_API CollisionManager
{
private:

public:
	bool CheckCollision(Entity2D &one, Entity2D &two);
};

#endif