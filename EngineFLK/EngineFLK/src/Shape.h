#ifndef SHAPE_H
#define SHAPE_H

#include "Exports.h"
#include "Entity2D.h"

enum class FLK_API PrimitiveType
{
	TRIANGLE,
	QUAD
};

class FLK_API Shape : public Entity2D
{
private:
	PrimitiveType type;

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
	Shape(Shader shader, PrimitiveType type, bool initalize = true);
	~Shape();

	void Init();

	void SetVertexColor(const Color& topRight, const Color& bottomRight, const Color& bottomLeft, const Color& topLeft) override;
	void SetVertexColor(const Color& color) override;

	void Draw();
};

#endif