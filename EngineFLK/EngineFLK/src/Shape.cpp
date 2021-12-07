#include "Shape.h"
#include "Texture.h"
#include "Color.h"
#include "Renderer.h"
Shape::Shape()
{

}

Shape::Shape(Shader shader, PrimitiveType type, bool initalize) : Entity2D(shader)
{
	this->type = type;

	if (initalize)
	{
		Init();
	}
}

Shape::~Shape()
{

}

void Shape::Init() 
{
	switch (type)
	{
	case PrimitiveType::TRIANGLE:
		vertexBuffer.SetData(triangleVertices, triangleVerticesAmount);
		
		vertexArray.Push<float>(2);
		vertexArray.Push<float>(4);

		vertexArray.SetData(vertexBuffer);

		indexBuffer.SetData(triangleIndices, triangleIndicesAmount);
		break;

	case PrimitiveType::QUAD:
		vertexBuffer.SetData(quadVertices, quadVerticesAmount);

		vertexArray.Push<float>(2);
		vertexArray.Push<float>(4);
		vertexArray.Push<float>(2);

		vertexArray.SetData(vertexBuffer);

		indexBuffer.SetData(quadIndices, quadIndicesAmount);
		break;
	}
}
void Shape::SetVertexColor(const Color& color)
{
	switch (type)
	{
	case PrimitiveType::TRIANGLE:
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

	case PrimitiveType::QUAD:
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

void Shape::SetVertexColor(const Color& topRight, const Color& bottomRight, const Color& bottomLeft, const Color& topLeft)
{
	switch (type)
	{
	case PrimitiveType::TRIANGLE:
		triangleVertices[2] = topRight.r;
		triangleVertices[3] = topRight.g;
		triangleVertices[4] = topRight.b;
		triangleVertices[5] = topRight.a;

		triangleVertices[8] = bottomRight.r;
		triangleVertices[9] = bottomRight.g;
		triangleVertices[10] = bottomRight.b;
		triangleVertices[11] = bottomRight.a;

		triangleVertices[14] = bottomLeft.r;
		triangleVertices[15] = bottomLeft.g;
		triangleVertices[16] = bottomLeft.b;
		triangleVertices[17] = bottomLeft.a;

		vertexBuffer.SetData(triangleVertices, triangleVerticesAmount);
		break;

	case PrimitiveType::QUAD:
		quadVertices[2] = topRight.r;
		quadVertices[3] = topRight.g;
		quadVertices[4] = topRight.b;
		quadVertices[5] = topRight.a;

		quadVertices[10] = bottomRight.r;
		quadVertices[11] = bottomRight.g;
		quadVertices[12] = bottomRight.b;
		quadVertices[13] = bottomRight.a;

		quadVertices[18] = bottomLeft.r;
		quadVertices[19] = bottomLeft.g;
		quadVertices[20] = bottomLeft.b;
		quadVertices[21] = bottomLeft.a;

		quadVertices[26] = topLeft.r;
		quadVertices[27] = topLeft.g;
		quadVertices[28] = topLeft.b;
		quadVertices[29] = topLeft.a;

		vertexBuffer.SetData(quadVertices, quadVerticesAmount);
		break;
	}

	vertexArray.SetData(vertexBuffer);
}

void Shape::Draw() 
{
	Renderer::GetInstance().Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);
}