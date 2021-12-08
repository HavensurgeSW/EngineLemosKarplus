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

void Tile::SetId(unsigned int id) 
{
	this->id = id;
}
