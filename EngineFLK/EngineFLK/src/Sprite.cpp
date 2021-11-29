#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Renderer* renderer, Shader& shader, bool initalize) : Entity2D()
{
	this->renderer = renderer;
	this->shader = shader;

	if (initalize)
	{
		Init();
	}
}

Sprite::~Sprite()
{
	UnbindBuffers();
	DeleteBuffers();
}

void Sprite::SetRenderer(Renderer* renderer)
{
	this->renderer = renderer;
}

void Sprite::SetShader(Shader& shader)
{
	this->shader = shader;
}

void Sprite::Init()
{
	vertexBuffer.SetData(quadVertices, 16);

	vertexArray.Push<float>(2);
	vertexArray.Push<float>(2);
	vertexArray.SetData(vertexBuffer);

	indexBuffer.SetData(quadIndices, 6);

	shader.Bind();
	shader.SetTextureUniform(0);
	shader.Unbind();
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

void Sprite::UnbindBuffers()
{
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	indexBuffer.Unbind();
	shader.Unbind();
}

void Sprite::DeleteBuffers()
{
	vertexArray.Delete();
	vertexBuffer.Delete();
	indexBuffer.Delete();
	shader.Delete();
}
