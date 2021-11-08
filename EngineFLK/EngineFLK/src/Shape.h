#ifndef SHAPE_H
#define SHAPE_H

#include "Exports.h"
#include "Shader.h"
#include "Entity2D.h"
#include "Transform.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"


enum FLK_API ShapeType //Primitive?
{
	TRIANGLE,
	QUAD
};

class FLK_API Shape : public Entity2D
{
private:	
	ShapeType type;
	Shader shader;

	float triangleVertices[6] =
	{
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f 
	};
	unsigned int triangleIndices[3] =
	{
		0, 1, 2
	};

	float quadVertices[16] =
	{
		 0.5f,  0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 0.0f, 
	    -0.5f, -0.5f, 1.0f, 1.0f,
	    -0.5f,  0.5f, 0.0f, 1.0f
	};
	unsigned int quadIndices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	VertexBuffer vertexBuffer;
	VertexArray vertexArray;
	IndexBuffer indexBuffer;

public:
	Transform transform;

	Shape();
	Shape(Renderer* renderer, Shader& shader, ShapeType type, bool initalize = true);
	~Shape();

	void Init();
	
	void SetRenderer(Renderer* renderer);
	void SetShader(Shader& shader);
	//void SetShapeType(ShapeType type);   //why tf would you change this in runtime
	void SetColor(Color color);
	void Draw();

private:
	void UnbindBuffers();
	void DeleteBuffers();
};

#endif