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

	void SetVertexArrayData(const VertexBuffer& vertexBuffer, const VertexBufferLayout& vertexBufferLayout);

	void SetVertexAttribute(const char* name);
	void Bind() const;
	void Unbind() const;
	void Delete(); 
};

#endif