#include "Entity2D.h"


Entity2D::Entity2D()
{

}

Entity2D::Entity2D(Renderer* renderer, Shader& shader)
{
	this->renderer = renderer;
	this->shader = shader;
}

Entity2D::~Entity2D()
{

}


void Entity2D::UnbindBuffers()
{
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	indexBuffer.Unbind();
	shader.Unbind();
}

void Entity2D::DeleteBuffers()
{
	vertexArray.Delete();
	vertexBuffer.Delete();
	indexBuffer.Delete();
	shader.Delete();
}
