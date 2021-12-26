#include "Tile.h"


Tile::Tile() 
{

}

Tile::Tile(unsigned int id, bool isWalkable, Shader& shader) : Sprite()
{
	this->id = id;
	this->isWalkable = isWalkable;
	this->shader = shader;
}

Tile::~Tile() 
{

}

void Tile::SetIsWalkable(bool value) 
{
	isWalkable = value;
}

bool Tile::GetIsWalkable() 
{
	return isWalkable;
}

unsigned int Tile::GetID() 
{
	return id;
}

void Tile::SetID(unsigned int value) 
{
	id = value;
}

