#ifndef ENTITY2D_H
#define ENTITY2D_H

#include "Exports.h"

#include "Renderer.h"

#include <iostream>

class FLK_API Entity2D
{
protected:	
	Renderer* renderer;

protected:
	Shader shader;

	VertexBuffer vertexBuffer;
	VertexArray vertexArray;
	IndexBuffer indexBuffer;

	void UnbindBuffers();
	void DeleteBuffers();

public:
	Entity2D();
	Entity2D(Renderer* renderer, Shader& shader);
	~Entity2D();

	Transform transform;
};

#endif