#pragma once

#include "Exports.h"
#include "Renderer.h"
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
	Renderer* renderer;
	ShapeType type;
	Shader shader;

	VertexBuffer vertexBuffer;
	VertexArray vertexArray;
	IndexBuffer indexBuffer;

	float triangleVertices[6] = 
	{
		-0.5f, -0.5f, // 0.0f, 0.5f, 0.5f, 0.0f,
		 0.5f, -0.5f, // 0.0f, 0.5f, 0.5f, 0.0f,
		 0.0f,  0.5f // 0.0f, 0.0f, 0.0f, 1.0f
	};
	unsigned int triangleIndices[3] = 
	{
		0,1,2
	};

	float quadVertices[8] = 
	{
		0.5f,  0.5f, //0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, //0.0f, 1.0f, 0.0f, 0.0f,
	   -0.5f, -0.5f, //0.0f, 1.0f, 0.0f, 0.0f,
	   -0.5f,  0.5f //0.0f, 1.0f, 0.0f, 0.0f
	};
	unsigned int quadIndices[6] = 
	{
		0,1,3,
		1,2,3
	};

public:
	Transform transform;

	Shape();
	Shape(Renderer* renderer, Shader shader);
	Shape(Renderer* renderer, Shader shader, ShapeType type);
	~Shape();

	void Init();

	void SetRenderer(Renderer* renderer);
	void SetShader(Shader shader);
	void SetShapeType(ShapeType type);
	void SetColor(Color color);
	void Draw();

	void Bind();
	void UnbindBuffers();
	void DeleteBuffers();
};
