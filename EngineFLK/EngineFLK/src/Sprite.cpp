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
	VertexBufferLayout layout;

	vertexBuffer.SetData(quadVertices, 16);
	layout.Push<float>(2);
	layout.Push<float>(2);
	vertexArray.SetVertexArrayData(vertexBuffer, layout);
	indexBuffer.SetData(quadIndices, 6);

	shader.Bind();
	shader.SetTextureUniform(0);
}

void Sprite::SetColor(Color color)
{
	shader.SetColorUniform(color);
}

void Sprite::SetTexture(const std::string& path)
{
	texture.LoadTexture(path);
	texture.Bind();
}

void Sprite::Draw()
{
	renderer->Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);
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
