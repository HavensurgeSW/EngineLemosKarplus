#include "Shape.h"
#include "Texture.h"

Shape::Shape()
{

}

Shape::Shape(Renderer* renderer, Shader& shader, ShapeType type, bool initalize) : Entity2D()
{
	this->renderer = renderer;
	this->shader = shader;
	this->type = type;

	if (initalize)
	{
		Init();
	}
}

Shape::~Shape()
{
	UnbindBuffers();
	DeleteBuffers();
}

void Shape::SetTexture(const std::string& path)
{
	texture.LoadTexture(path);
	texture.Bind();
}

void Shape::SetRenderer(Renderer* renderer)
{
	this->renderer = renderer;
}

void Shape::SetShader(Shader& shader)
{
	this->shader = shader;
}

void Shape::Init() 
{
	VertexBufferLayout layout;
	switch (type)
	{
	case ShapeType::TRIANGLE:
		vertexBuffer.SetData(triangleVertices, 12);
		layout.Push<float>(2);
		layout.Push<float>(2);		
		vertexArray.SetVertexArrayData(vertexBuffer, layout);
		indexBuffer.SetData(triangleIndices, 3);
		break;

	case ShapeType::QUAD:
		vertexBuffer.SetData(quadVertices, 16);
		layout.Push<float>(2);


		layout.Push<float>(2);
		vertexArray.SetVertexArrayData(vertexBuffer, layout);
		indexBuffer.SetData(quadIndices, 6);
		break;
	}

	shader.Bind();
	shader.SetTextureUniform(0);
	texture.Unbind();
}

void Shape::SetColor(Color color)
{
	shader.SetColorUniform(color);
}

void Shape::Draw() 
{
	renderer->Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);
}

void Shape::UnbindBuffers()
{
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	indexBuffer.Unbind();
	shader.Unbind();
}

void Shape::DeleteBuffers()
{
	vertexArray.Delete();
	vertexBuffer.Delete();
	indexBuffer.Delete();
	shader.Delete();
}
