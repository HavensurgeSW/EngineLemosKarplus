#include "Sprite.h"
#include "Color.h"
#include "Texture.h"
#include "Renderer.h"
#include "Vector4.h"

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

void Sprite::SetUVs(Vector4 uvs)
{
	this->uvs[0].u = uvs.x + uvs.z;
	this->uvs[0].v = uvs.y + uvs.w;

	this->uvs[1].u = uvs.x + uvs.z;
	this->uvs[1].v = uvs.y;

	this->uvs[2].u = uvs.x;
	this->uvs[2].v = uvs.y;
	
	this->uvs[3].u = uvs.x;
	this->uvs[3].v = uvs.y + uvs.w;
}

void Sprite::UpdateTextureCoordinates()
{
	quadVertices[6] = uvs[0].u;
	quadVertices[7] = uvs[0].v;

	quadVertices[14] = uvs[1].u;
	quadVertices[15] = uvs[1].v;

	quadVertices[22] = uvs[2].u;
	quadVertices[23] = uvs[2].v;

	quadVertices[30] = uvs[3].u;
	quadVertices[31] = uvs[3].v;
}

void Sprite::Draw()
{
	texture.Bind();	
	Renderer::GetInstance().Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);
	texture.Unbind();
}