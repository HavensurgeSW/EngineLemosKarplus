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
}

Shape::~Shape()
{

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

}

void Shape::Draw()
{
	//renderer->DrawElement();
}