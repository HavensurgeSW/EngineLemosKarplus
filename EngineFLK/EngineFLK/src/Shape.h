#ifndef SHAPE_H
#define SHAPE_H

#include "Exports.h"
#include "Entity2D.h"

enum FLK_API ShapeType //Primitive?
{
	TRIANGLE,
	QUAD
};

class FLK_API Shape : public Entity2D
{
private:
	ShapeType type;

	static const int triangleVerticesAmount = 18;
	float triangleVertices[triangleVerticesAmount] =
	{    //position           //Colors         
		-0.5f, -0.5f,   1.0f, 1.0f, 1.0f, 1.0f, 
		 0.5f, -0.5f,   1.0f, 1.0f, 1.0f, 1.0f,
		 0.0f,  0.5f,   1.0f, 1.0f, 1.0f, 1.0f
	};

	static const int triangleIndicesAmount = 3;
	unsigned int triangleIndices[triangleIndicesAmount] =
	{
		0, 1, 2
	};

public:
	Shape();
	Shape(Renderer* renderer, Shader shader, ShapeType type, bool initalize = true);
	~Shape();

	void Init();
	
	void SetShaderColor(Color color);
	void SetVertexColor(Color color);
	void SetVertexColor(Color vertex1Color, Color vertex2Color, Color vertex3Color, Color vertex4Color);
	
	void Draw();
};

#endif