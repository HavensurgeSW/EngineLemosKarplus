#include "Entity2D.h"

#include "Color.h"
Entity2D::Entity2D()
{
	//renderer = Renderer::GetInstance();   //not having this causes errors
}

Entity2D::Entity2D(Shader& shader)
{
	//renderer = Renderer::GetInstance();   //not having this causes errors
	this->shader = shader;
}

Entity2D::~Entity2D()
{
	UnbindBuffers();
	DeleteBuffers();
}

void Entity2D::SetColorTint(Color color)
{
	shader.Bind();
	shader.SetColorUniform(color);
	shader.Unbind();
}

void Entity2D::SetVertexColor(const Color& topRight, const Color& bottomRight, const Color& bottomLeft, const Color& topLeft)
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

void Entity2D::SetVertexColor(const Color& color)
{
	quadVertices[2] = color.r;
	quadVertices[3] = color.g;
	quadVertices[4] = color.b;
	quadVertices[5] = color.a;

	quadVertices[10] = color.r;
	quadVertices[11] = color.g;
	quadVertices[12] = color.b;
	quadVertices[13] = color.a;

	quadVertices[18] = color.r;
	quadVertices[19] = color.g;
	quadVertices[20] = color.b;
	quadVertices[21] = color.a;

	quadVertices[26] = color.r;
	quadVertices[27] = color.g;
	quadVertices[28] = color.b;
	quadVertices[29] = color.a;

	vertexBuffer.SetData(quadVertices, quadVerticesAmount);
	vertexArray.SetData(vertexBuffer);
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
