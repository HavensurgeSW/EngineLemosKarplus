#include "Shape.h"

Shape::Shape()
{

}

Shape::Shape(Renderer* renderer, Shader& shader)
{
	this->renderer = renderer;
	this->shader = shader;
}

Shape::Shape(Renderer* renderer, Shader& shader, ShapeType type)
{
	this->renderer = renderer;
	this->shader = shader;
	this->type = type;
}

Shape::~Shape()
{

}

void Shape::SetRenderer(Renderer* renderer)
{
	this->renderer = renderer;
}

void Shape::SetShader(Shader& shader)
{
	this->shader = shader;
}

void Shape::SetShapeType(ShapeType type)
{
	this->type = type;
}

void Shape::Init() {

	switch (type)
	{
	case ShapeType::TRIANGLE:
		renderer->GenerateBuffers(triangleVertices, 6, triangleIndices, 3);
		break;

	case ShapeType::QUAD:
		renderer->GenerateBuffers(quadVertices, 8, quadIndices, 6);
		break;
	}

	//shader.SetColorUniform(Color::White());
	//shader.SetTransformUniform(transform);
}

void Shape::SetColor(Color color)
{
	shader.SetColorUniform(color);
}

void Shape::Draw() 
{
	renderer->Draw(shader);
	//shader.Unbind();
}

void Shape::Bind()
{
	shader.SetTransformUniform(transform);
	shader.Bind();
}