#include "IndexBuffer.h"

#include "glew.h"
#include "ErrorHandling.h"

IndexBuffer::IndexBuffer()
{
}

IndexBuffer::IndexBuffer(const unsigned int indices[], unsigned int indexCount)
{
	GLCheck(glGenBuffers(1, &bufferId));
	GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId));
	GLCheck(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW));
	this->indexCount = indexCount;
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &bufferId);
}

void IndexBuffer::SetData(const unsigned int indices[], unsigned int indexCount)
{
	GLCheck(glGenBuffers(1, &bufferId));
	GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId));
	GLCheck(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW));
	this->indexCount = indexCount;
}

void IndexBuffer::Bind() const
{
	GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId)); //saves a segment of memory to the specified buffer
}

void IndexBuffer::Unbind() const
{
	GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void IndexBuffer::Delete() const
{
	GLCheck(glDeleteBuffers(1, &bufferId));
}

unsigned int IndexBuffer::GetIndexCount() const
{
	return indexCount;
}
