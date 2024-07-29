#include "Tile.h"

Tile::Tile() 
{
	
	id = 0;
	isWalkable = false;
}

Tile::Tile(Shader& shader, bool initalize) : Sprite(shader, initalize) {
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

void Tile::SetId(unsigned int id) 
{
	this->id = id;
}

void Tile::Draw() {
	vertexBuffer.SetData(quadVertices, quadVerticesAmount);
	vertexArray.SetData(vertexBuffer);

	Sprite::Draw();
	
}
