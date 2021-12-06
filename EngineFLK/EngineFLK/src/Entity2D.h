#ifndef ENTITY2D_H
#define ENTITY2D_H

#include "Exports.h"

#include "Renderer.h"

#include <iostream>

class FLK_API Entity2D
{
protected:	
	Renderer& renderer = Renderer::GetInstance();  //not having this causes errors

protected:
	Shader shader;

	static const int quadVerticesAmount = 32;
	float quadVertices[quadVerticesAmount] =
	{	 //position            //colors           //texture coords    
		 0.5f,  0.5f,    1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 1.0f,
		 0.5f, -0.5f,    1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 0.0f,
		-0.5f, -0.5f,    1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 0.0f,
		-0.5f,  0.5f,    1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f
	};

	static const int quadIndicesAmount = 6;
	unsigned int quadIndices[quadIndicesAmount] =
	{
		0, 1, 3,
		1, 2, 3
	};

	VertexBuffer vertexBuffer;
	VertexArray vertexArray;
	IndexBuffer indexBuffer;

	void UnbindBuffers();
	void DeleteBuffers();

public:
	Entity2D();
	Entity2D(Shader& shader);
	virtual ~Entity2D();

	void SetColorTint(Color color);

	virtual void SetVertexColor(const Color& topRight, const Color& bottomRight, const Color& bottomLeft, const Color& topLeft);
	virtual void SetVertexColor(const Color& color);

	Transform transform;
};

#endif