#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Renderer* renderer, Shader& shader, bool initialize) : Entity2D(renderer, shader)
{
	if (initialize)
	{
		Init();
	}
}

Sprite::~Sprite()
{
	UnbindBuffers();
	DeleteBuffers();
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

void Sprite::SetColor(Color color)
{
	shader.Bind();
	shader.SetColorUniform(color);
	shader.Unbind();
}


void Sprite::SetTexture(const std::string& path)
{
	texture.LoadTexture(path);

	shader.Bind();
	shader.SetColorUniform(Color::White());
	shader.Unbind();
}


void Sprite::Draw()
{
	texture.Bind();	
	renderer->Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);	
	texture.Unbind();
}