#include "Tile.h"

Tile::Tile() 
{
	
	id = 0;
	isWalkable = true;
}

Tile::Tile(Shader& shader, bool initalize) : Sprite(shader, initalize) {
	id = 0;
	isWalkable = true;


}

Tile::~Tile() 
{
}

bool Tile::GetIsWalkable() const
{
	return isWalkable;
}

void Tile::SetIsWalkable(bool isWalkable)
{
	this->isWalkable = isWalkable;
}

unsigned int Tile::GetId() const
{
	return id;
}

void Tile::SetTextureCoordinates(Vector2 topRight, Vector2 bottomRight, Vector2 bottomLeft, Vector2 topLeft)
{
	Sprite::SetTextureCoordinates(topRight, bottomRight, bottomLeft, topLeft);
	vertexBuffer.SetData(quadVertices, quadVerticesAmount);
	vertexArray.SetData(vertexBuffer);

}




void Tile::SetId(unsigned int id) 
{
	this->id = id;
}

void Tile::Draw() {

	Sprite::Draw();	
}
