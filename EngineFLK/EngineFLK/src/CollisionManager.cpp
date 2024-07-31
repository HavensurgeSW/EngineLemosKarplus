#include "CollisionManager.h"

#include "Entity2D.h"

bool CollisionManager::CheckCollision(const Entity2D* one, const Entity2D* two)
{
    // collision x-axis?
    bool collisionX = one->transform.GetPosition().x + one->transform.GetScale().x >= two->transform.GetPosition().x &&
        two->transform.GetPosition().x + two->transform.GetScale().x >= one->transform.GetPosition().x;
    // collision y-axis?
    bool collisionY = one->transform.GetPosition().y + one->transform.GetScale().y >= two->transform.GetPosition().y &&
        two->transform.GetPosition().y + one->transform.GetScale().y >= one->transform.GetPosition().y;
    // collision only if on both axes

   
    return collisionX && collisionY;
}

bool CollisionManager::UpdateCollisions(Tilemap* tilemap, Entity2D* actor)
{
    float leftX = actor->transform.GetPosition().x;
    float rightX = actor->transform.GetPosition().x + actor->transform.GetScale().x;
    float topY = actor->transform.GetPosition().y;
    float bottomY = actor->transform.GetPosition().y + actor->transform.GetScale().y;

    float leftTile = static_cast<int>((leftX + 1.0f) / 2.0f * tilemap->GetMapDim().x);
	float rightTile = static_cast<int>((rightX + 1.0f) / 2.0f * tilemap->GetMapDim().x);
    float topTile = static_cast<int>((topY + 1.0f) / 2.0f * tilemap->GetMapDim().y);
    float bottomTile = static_cast<int>((bottomY + 1.0f) / 2.0f * tilemap->GetMapDim().y);
    
    if (Input::GetKey(KeyCode::ENTER)) {
        std::cout <<"Player position: " << "X: " << actor->transform.GetPosition().x << " Y: " << actor->transform.GetPosition().y << std::endl;
        //std::cout << "Left Tile position: " << leftTile << std::endl;
        //std::cout << "Right Tile position: " << rightTile << std::endl;
        //std::cout << "Top Tile position: " << topTile << std::endl;
        //std::cout << "Bottom Tile position: " << bottomTile << std::endl;
    }

    if(tilemap->getTile(0, 0)->GetIsWalkable())
    std::cout << "something going on! " << std::endl;

    for (int y = topTile; y <= bottomTile; ++y) {
        for (int x = leftTile; x <= rightTile; ++x) {
                
            if (!tilemap->getTile(x,y)->GetIsWalkable()){

                // Create a temporary Entity2D for the tile
                Entity2D* tileEntity = new Entity2D();
                tileEntity->transform.SetPosition(static_cast<float>(x * tilemap->getSheet()->GetSpriteDim().x), static_cast<float>(y * tilemap->getSheet()->GetSpriteDim().y), 0.0f);
                  
                if (CheckCollision(actor, tileEntity)) {
                    
                    return true; // Collision detected
                }
            }
        }
    }

}


Vector2 WorldToTile() {
    
}