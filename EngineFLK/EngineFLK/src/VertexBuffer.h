#pragma once
#include "Exports.h"

class FLK_API VertexBuffer
{
private:
	unsigned int rendererId;

public:

	VertexBuffer();
	VertexBuffer(int verticesAmount, float vertices[]);
	~VertexBuffer();

	void GenerateBuffer(int verticesAmount, float vertices[]);

	void Bind();
	void Unbind();
};