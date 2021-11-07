#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int arrayId;

public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& vertexBufferLayout);

	void GenerateVertexArray();
	void SetVertexAttribute(const char* name);
	void Bind() const;
	void Unbind() const;
	void Delete(); 
};

#endif