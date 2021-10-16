#include "VertexBuffer.h"
#include "glew.h"
#include "ErrorHandling.h"

VertexBuffer::VertexBuffer()
{
}

VertexBuffer::VertexBuffer(int verticesAmount, float vertices[]) //byteSize should be something like (amountOfVertices * sizeof(float in this case)
{
	GLCheck(glGenBuffers(1, &rendererId));
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, rendererId));
	GLCheck(glBufferData(GL_ARRAY_BUFFER, verticesAmount * sizeof(vertices), vertices, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	//GLCheck(glDeleteBuffers(1, &rendererId));
	//ERROR: Since in this case the buffer its allocated in heap (renderer.cpp GenerateBuffers method)
	//the destructor gets called as soon as the method where the index buffer is,
	//ends, making the program break when trying to DrawElement()
}

void VertexBuffer::GenerateBuffer(int verticesAmount, float vertices[])
{
	GLCheck(glGenBuffers(1, &rendererId));
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, rendererId));
	GLCheck(glBufferData(GL_ARRAY_BUFFER, verticesAmount * sizeof(vertices), vertices, GL_STATIC_DRAW));
}

void VertexBuffer::Bind()
{
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, rendererId));
}

void VertexBuffer::Unbind()
{
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

//void VertexBuffer::SetData(const void* data, unsigned int size)
//{
//	glGenBuffers(1, &rendererId);
//	glBindBuffer(GL_ARRAY_BUFFER, rendererId);
//	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);
//}