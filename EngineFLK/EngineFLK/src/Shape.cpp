#include "Shape.h"

Shape::Shape()
{

}

Shape::Shape(Renderer* renderer, Shader shader)
{
	this->renderer = renderer;
	this->shader = shader;
}

Shape::Shape(Renderer* renderer, Shader shader, ShapeType type)
{
	this->renderer = renderer;
	this->shader = shader;
	this->type = type;
	this->type = type;
}

Shape::~Shape()
{
	UnbindBuffers();
	DeleteBuffers();
}

void Shape::SetRenderer(Renderer* renderer)
{
	this->renderer = renderer;
}

void Shape::SetShader(Shader shader)
{
	this->shader = shader;
}

void Shape::SetShapeType(ShapeType type)
{
	this->type = type;
}

void Shape::Init() {
	vertexArray.GenerateVertexArray();
	vertexArray.Bind();

	switch (type)
	{
	case ShapeType::TRIANGLE:
		vertexBuffer.SetData(triangleVertices, 6);
		indexBuffer.SetData(triangleIndices, 3);
		break;

	case ShapeType::QUAD:
		vertexBuffer.SetData(quadVertices, 8);
		indexBuffer.SetData(quadIndices, 6);
		break;
	}

	//shader.SetVertexAttributes("position");
	//shader.SetColorAttributes("color");
}

void Shape::SetColor(Color color) 
{
	shader.SetColorUniform(color);
}

void Shape::Draw() {
	switch (type)
	{
	case ShapeType::TRIANGLE:
		vertexBuffer.SetData(triangleVertices, 6);
		indexBuffer.SetData(triangleIndices, 3);
		vertexArray.Bind();
		renderer->Draw(*this);
		break;

	case ShapeType::QUAD:
		vertexBuffer.SetData(quadVertices, 8);
		indexBuffer.SetData(quadIndices, 6);
		vertexArray.Bind();
		renderer->Draw(*this);
		break;
	}
}

void Shape::Bind()
{
	shader.SetTransformUniform(transform);
	shader.Bind();
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
}