#include "Tile.h"

Tile::Tile() 
{
	id = 0;
	isWalkable = false;
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
	quadVertices[6] = topRight.x;
	quadVertices[7] = topRight.y;

	quadVertices[14] = bottomRight.x;
	quadVertices[15] = bottomRight.y;

	quadVertices[22] = bottomLeft.x;
	quadVertices[23] = bottomLeft.y;

	quadVertices[30] = topLeft.x;
	quadVertices[31] = topLeft.y;

	vertexBuffer.SetData(quadVertices, quadVerticesAmount);
	vertexArray.SetData(vertexBuffer);
}

void Tile::SetId(unsigned int id) 
{
	this->id = id;
}
