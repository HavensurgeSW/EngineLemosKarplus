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
	//UnbindBuffers();
	//DeleteBuffers();
}

void Shape::Init() 
{
	switch (type)
	{
	case ShapeType::TRIANGLE:
		vertexBuffer.SetData(triangleVertices, triangleVerticesAmount);
		
		vertexArray.Push<float>(2);
		vertexArray.Push<float>(4);

		vertexArray.SetData(vertexBuffer);

		indexBuffer.SetData(triangleIndices, triangleIndicesAmount);
		break;

	case ShapeType::QUAD:
		vertexBuffer.SetData(quadVertices, quadVerticesAmount);

		vertexArray.Push<float>(2);
		vertexArray.Push<float>(4);
		vertexArray.Push<float>(2);

		vertexArray.SetData(vertexBuffer);

		indexBuffer.SetData(quadIndices, quadIndicesAmount);
		break;
	}
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

		vertexBuffer.SetData(triangleVertices, triangleVerticesAmount);
		break;

	case QUAD:
		quadVertices[2] = color.r;
		quadVertices[3] = color.g;
		quadVertices[4] = color.b;
		quadVertices[5] = color.a;

		quadVertices[10] = color.r;
		quadVertices[11] = color.g;
		quadVertices[12] = color.b;
		quadVertices[13] = color.a;

		quadVertices[18] = color.r;
		quadVertices[19] = color.g;
		quadVertices[20] = color.b;
		quadVertices[21] = color.a;

		quadVertices[26] = color.r;
		quadVertices[27] = color.g;
		quadVertices[28] = color.b;
		quadVertices[29] = color.a;

		vertexBuffer.SetData(quadVertices, quadVerticesAmount);
		break;
	}

	vertexArray.SetData(vertexBuffer);
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

		vertexBuffer.SetData(triangleVertices, triangleVerticesAmount);
		break;

	case QUAD:
		quadVertices[2] = vertex1Color.r;
		quadVertices[3] = vertex1Color.g;
		quadVertices[4] = vertex1Color.b;
		quadVertices[5] = vertex1Color.a;

		quadVertices[10] = vertex2Color.r;
		quadVertices[11] = vertex2Color.g;
		quadVertices[12] = vertex2Color.b;
		quadVertices[13] = vertex2Color.a;

		quadVertices[18] = vertex3Color.r;
		quadVertices[19] = vertex3Color.g;
		quadVertices[20] = vertex3Color.b;
		quadVertices[21] = vertex3Color.a;

		quadVertices[26] = vertex4Color.r;
		quadVertices[27] = vertex4Color.g;
		quadVertices[28] = vertex4Color.b;
		quadVertices[29] = vertex4Color.a;

		vertexBuffer.SetData(quadVertices, quadVerticesAmount);
		break;
	}

	vertexArray.SetData(vertexBuffer);
}

void Shape::Draw() 
{
	renderer->Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);
}