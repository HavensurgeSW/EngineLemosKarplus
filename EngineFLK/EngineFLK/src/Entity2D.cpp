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
	UnbindBuffers();
	DeleteBuffers();
}


void Entity2D::SetRenderer(Renderer* renderer)
{
	this->renderer = renderer;
}

void Entity2D::SetShader(Shader& shader)
{
	this->shader = shader;
}

void Entity2D::SetColorTint(Color color)
{
	shader.Bind();
	shader.SetColorUniform(color);
	shader.Unbind();
}

void Entity2D::SetVertexColor(Color topRight, Color bottomRight, Color bottomLeft, Color topLeft)
{
	quadVertices[2] = topRight.r;
	quadVertices[3] = topRight.g;
	quadVertices[4] = topRight.b;
	quadVertices[5] = topRight.a;

	quadVertices[10] = bottomRight.r;
	quadVertices[11] = bottomRight.g;
	quadVertices[12] = bottomRight.b;
	quadVertices[13] = bottomRight.a;

	quadVertices[18] = bottomLeft.r;
	quadVertices[19] = bottomLeft.g;
	quadVertices[20] = bottomLeft.b;
	quadVertices[21] = bottomLeft.a;

	quadVertices[26] = topLeft.r;
	quadVertices[27] = topLeft.g;
	quadVertices[28] = topLeft.b;
	quadVertices[29] = topLeft.a;

	vertexBuffer.SetData(quadVertices, quadVerticesAmount);
	vertexArray.SetData(vertexBuffer);
}

void Entity2D::SetVertexColor(Color color)
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
