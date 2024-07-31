#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "Exports.h"
#include <list>

#include "Tilemap.h"

class Entity2D;
class Tilemap;

class FLK_API CollisionManager
{
private:
	std::list<Entity2D*> dynamicCollisionList;
	std::list<Entity2D*> staticCollisionList;
public:
	bool CheckCollision(const Entity2D* one, const Entity2D* two);

	bool UpdateCollisions(Tilemap* tilemap, Entity2D* actor);

};

#endif