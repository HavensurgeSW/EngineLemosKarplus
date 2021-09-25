#include "IndexBuffer.h"
#include "glew.h"

IndexBuffer::IndexBuffer()
{

}

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int indexCount) : indexCount(indexCount)
{
	GLCheck(glGenBuffers(1, &rendererId);)
	GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);)
	GLCheck(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), data, GL_STATIC_DRAW);)
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
	GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);)
}

void IndexBuffer::Unbind()
{
	GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);)
}

unsigned int IndexBuffer::GetIndexCount() const
{
	return indexCount;
}
