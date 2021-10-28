#include "Shape.h"

Shape::Shape()
{

}

Shape::Shape(Renderer* renderer, Shader& shader, ShapeType type, bool initalize)
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
}

void Shape::SetRenderer(Renderer* renderer)
{
	this->renderer = renderer;
}

void Shape::SetShader(Shader& shader)
{
	this->shader = shader;
}

//void Shape::SetShapeType(ShapeType type)
//{
//	this->type = type;
//}

void Shape::Init() 
{
	vertexArray.GenerateVertexArray();
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

	shader.Bind();
	//shader.SetColorUniform(Color::White());
	//shader.SetTransformUniform(transform);
}

void Shape::SetColor(Color color)
{
	shader.SetColorUniform(color);
}

void Shape::Draw() 
{
	//BindBuffers();
	shader.SetTransformUniform(transform);
	renderer->Draw(shader, indexBuffer.GetIndexCount());
	//UnbindBuffers();
}

void Shape::BindBuffers()
{
	vertexArray.Bind();
	vertexBuffer.Bind();
	indexBuffer.Bind();
}

void Shape::UnbindBuffers()
{
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	indexBuffer.Unbind();
	shader.Unbind();
}