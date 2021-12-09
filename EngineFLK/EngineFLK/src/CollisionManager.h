#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "Exports.h"

class Entity2D;
struct Tile;

class FLK_API CollisionManager
{
private:

public:
	bool CheckCollision(const Entity2D* one, const Entity2D* two);
	bool CheckCollision(const Entity2D* one, const Tile* two);
};

#endif