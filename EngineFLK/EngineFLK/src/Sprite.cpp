#include "Sprite.h"
#include "Color.h"
#include "Texture.h"
#include "Renderer.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Shader& shader, bool initialize) : Entity2D(shader)
{
	if (initialize)
	{
		Init();
	}
}

Sprite::~Sprite()
{

}

void Sprite::Init()
{
	vertexBuffer.SetData(quadVertices, quadVerticesAmount);

	vertexArray.Push<float>(2);
	vertexArray.Push<float>(4);
	vertexArray.Push<float>(2);
	vertexArray.SetData(vertexBuffer);

	indexBuffer.SetData(quadIndices, quadIndicesAmount);

	//shader.Bind();
	//shader.SetTextureUniform(0);
	//shader.Unbind();
}

void Sprite::SetTexture(const std::string& path)
{
	texture.LoadTexture(path);
	SetColorTint(Color::White());
}

void Sprite::SetTexture(const Texture& texture)
{
	this->texture = texture;
	SetColorTint(Color::White());
}

void Sprite::SetTextureCoordinates(Vector2 topRight, Vector2 bottomRight, Vector2 bottomLeft, Vector2 topLeft)
{
	quadVertices[6] = topRight.x;
	quadVertices[7] = topRight.y;

	quadVertices[14] = bottomRight.x;
	quadVertices[15] = bottomRight.y;

	quadVertices[22] = bottomLeft.x;
	quadVertices[23] = bottomLeft.y;

	quadVertices[30] = topLeft.x;
	quadVertices[31] = topLeft.y;

	//vertexBuffer.SetData(quadVertices, quadVerticesAmount);
	//vertexArray.SetData(vertexBuffer);
}

void Sprite::Draw()
{
	texture.Bind();	
	Renderer::GetInstance().Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);
	texture.Unbind();
}