#include "IndexBuffer.h"
#include "glew.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int indexCount) : indexCount(indexCount)
{
	glGenBuffers(1, &rendererId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	//glDeleteBuffers(1, &rendererId); 
	//ERROR: Since in this case its allocated in heap, the destructor gets called as soon as 
	//the method where the index buffer is, ends, 
	//making the program break when trying to DrawElement()
}

void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId); //saves a segment of memory to the specified buffer
}

void IndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

inline unsigned int IndexBuffer::GetIndexCount() const
{
	return indexCount;
}
