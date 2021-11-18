#include "CollisionManager.h"

bool CollisionManager::CheckCollision(Entity2D& one, Entity2D& two)
{
    // collision x-axis?
    bool collisionX = one.transform.GetPosition().x + one.transform.GetScale().x >= two.transform.GetPosition().x &&
        two.transform.GetPosition().x + two.transform.GetScale().x >= one.transform.GetPosition().x;
    // collision y-axis?
    bool collisionY = one.transform.GetPosition().y + one.transform.GetScale().y >= two.transform.GetPosition().y &&
        two.transform.GetPosition().y + one.transform.GetScale().y >= one.transform.GetPosition().y;
    // collision only if on both axes

   
    return collisionX && collisionY;
}
