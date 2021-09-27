#include "Shape.h"

Shape::Shape()
{
	//positions = //Vertices
	//{
	//	-0.5f, -0.5f, //vertex 0
	//	 0.5f, -0.5f, //vertex 1
	//	 0.5f,  0.5f, //vertex 2
	//	-0.5f,  0.5f  //vertex 3 for square
	//};
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

void Shape::SetPositions(float* arr)
{
	int size = *(&arr + 1) - arr;
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	std::cout << arrSize << std::endl;
}