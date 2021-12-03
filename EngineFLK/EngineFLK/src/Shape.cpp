#include "Shape.h"
#include "Texture.h"

Shape::Shape()
{

}

Shape::Shape(Renderer* renderer, Shader shader, ShapeType type, bool initalize) : Entity2D(renderer, shader)
{
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

void Shape::Init() 
{
	switch (type)
	{
	case ShapeType::TRIANGLE:
		vertexBuffer.SetData(triangleVertices, 18);
		
		vertexArray.Push<float>(2);
		vertexArray.Push<float>(4);
		vertexArray.SetData(vertexBuffer);

		indexBuffer.SetData(triangleIndices, 3);
		break;

	case ShapeType::QUAD:
		vertexBuffer.SetData(quadVertices, 24);

		vertexArray.Push<float>(2);
		vertexArray.Push<float>(4);
		vertexArray.SetData(vertexBuffer);

		indexBuffer.SetData(quadIndices, 6);
		break;
	}
}

void Shape::SetShaderColor(Color color)
{
	shader.Bind();
	shader.SetColorUniform(color);
	shader.Unbind();
}

void Shape::SetVertexColor(Color color)
{
	switch (type)
	{
	case TRIANGLE:
		triangleVertices[2] = color.r;
		triangleVertices[3] = color.g;
		triangleVertices[4]	= color.b;
		triangleVertices[5]	= color.a;

		triangleVertices[8]= color.r;
		triangleVertices[9]= color.g;
		triangleVertices[10]= color.b;
		triangleVertices[11]= color.a;

		triangleVertices[14]= color.r;
		triangleVertices[15]= color.g;
		triangleVertices[16]= color.b;
		triangleVertices[17]= color.a;
		break;

	case QUAD:
		quadVertices[2] = color.r;
		quadVertices[3] = color.g;
		quadVertices[4] = color.b;
		quadVertices[5] = color.a;

		quadVertices[8] = color.r;
		quadVertices[9] = color.g;
		quadVertices[10] = color.b;
		quadVertices[11] = color.a;

		quadVertices[14] = color.r;
		quadVertices[15] = color.g;
		quadVertices[16] = color.b;
		quadVertices[17] = color.a;

		quadVertices[20] = color.r;
		quadVertices[21] = color.g;
		quadVertices[22] = color.b;
		quadVertices[23] = color.a;
		break;
	}
}

void Shape::SetVertexColor(Color vertex1Color, Color vertex2Color, Color vertex3Color, Color vertex4Color)
{
	switch (type)
	{
	case TRIANGLE:
		triangleVertices[2] = vertex1Color.r;
		triangleVertices[3] = vertex1Color.g;
		triangleVertices[4] = vertex1Color.b;
		triangleVertices[5] = vertex1Color.a;

		triangleVertices[8] = vertex2Color.r;
		triangleVertices[9] = vertex2Color.g;
		triangleVertices[10] = vertex2Color.b;
		triangleVertices[11] = vertex2Color.a;

		triangleVertices[14] = vertex3Color.r;
		triangleVertices[15] = vertex3Color.g;
		triangleVertices[16] = vertex3Color.b;
		triangleVertices[17] = vertex3Color.a;
		break;

	case QUAD:
		quadVertices[2] = vertex1Color.r;
		quadVertices[3] = vertex1Color.g;
		quadVertices[4] = vertex1Color.b;
		quadVertices[5] = vertex1Color.a;

		quadVertices[8] = vertex2Color.r;
		quadVertices[9] = vertex2Color.g;
		quadVertices[10] = vertex2Color.b;
		quadVertices[11] = vertex2Color.a;

		quadVertices[14] = vertex3Color.r;
		quadVertices[15] = vertex3Color.g;
		quadVertices[16] = vertex3Color.b;
		quadVertices[17] = vertex3Color.a;

		quadVertices[20] = vertex4Color.r;
		quadVertices[21] = vertex4Color.g;
		quadVertices[22] = vertex4Color.b;
		quadVertices[23] = vertex4Color.a;
		break;
	}
}

void Shape::Draw() 
{
	renderer->Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);
}