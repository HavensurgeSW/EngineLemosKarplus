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

	float triangleVertices[18] =
	{    //position           //Colors         
		-0.5f, -0.5f,   1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,   1.0f, 1.0f, 1.0f, 1.0f,
		 0.0f,  0.5f,   1.0f, 1.0f, 1.0f, 1.0f
	};
	unsigned int triangleIndices[3] =
	{
		0, 1, 2
	};

	float quadVertices[24] =
	{	 //position           //colors         
		 0.5f,  0.5f,   1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,   1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,   1.0f, 1.0f, 1.0f, 1.0f,
	    -0.5f,  0.5f,   1.0f, 1.0f, 1.0f, 1.0f 
	};
	unsigned int quadIndices[6] =
	{
		0, 1, 3,
		1, 2, 3
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