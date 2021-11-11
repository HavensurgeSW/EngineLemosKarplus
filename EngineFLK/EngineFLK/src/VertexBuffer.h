#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

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

	void Bind() const;
	void Unbind() const;
	void Delete() const;
};

#endif