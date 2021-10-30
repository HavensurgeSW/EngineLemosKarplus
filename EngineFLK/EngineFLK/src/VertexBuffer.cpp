#include "VertexBuffer.h"
#include "glew.h"
#include "ErrorHandling.h"

VertexBuffer::VertexBuffer()
{
}

VertexBuffer::VertexBuffer(float vertices[], int verticesAmount) //byteSize should be something like (amountOfVertices * sizeof(float in this case)
{
	GLCheck(glGenBuffers(1, &bufferId));
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, bufferId));
	GLCheck(glBufferData(GL_ARRAY_BUFFER, verticesAmount * sizeof(vertices), vertices, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	//GLCheck(glDeleteBuffers(1, &rendererId));
	//ERROR: Since in this case the buffer its allocated in heap (renderer.cpp GenerateBuffers method)
	//the destructor gets called as soon as the method where the index buffer is,
	//ends, making the program break when trying to DrawElement()
}

void VertexBuffer::SetData(float vertices[], int verticesAmount)
{
	GLCheck(glGenBuffers(1, &bufferId));
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, bufferId));
	GLCheck(glBufferData(GL_ARRAY_BUFFER, verticesAmount * sizeof(vertices), vertices, GL_STATIC_DRAW));

	GLCheck(glEnableVertexAttribArray(0)); //enables or "turns on" the specified attribute
	GLCheck(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));

	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::Bind()
{
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, bufferId));
}

void VertexBuffer::Unbind()
{
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::Delete()
{
	GLCheck(glDeleteBuffers(1, &bufferId));
}
