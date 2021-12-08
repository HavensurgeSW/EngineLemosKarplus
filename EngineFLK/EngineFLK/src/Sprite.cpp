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

void Sprite::Draw()
{
	texture.Bind();	
	Renderer::GetInstance().Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);
	texture.Unbind();
}