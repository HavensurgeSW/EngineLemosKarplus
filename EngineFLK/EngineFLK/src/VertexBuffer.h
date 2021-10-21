#pragma once
#include "Exports.h"

class FLK_API VertexBuffer
{
private:
	unsigned int bufferId;

public:

	VertexBuffer();
	VertexBuffer(float vertices[], int verticesAmount);
	~VertexBuffer();

	void SetData(float vertices[], int verticesAmount);

	void Bind();
	void Unbind();
	void Delete();
};