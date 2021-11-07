#include "VertexArray.h"

#include "glew.h"
#include "ErrorHandling.h"

VertexArray::VertexArray()
{
	GLCheck(glGenVertexArrays(1, &arrayId));
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &arrayId);
}

void VertexArray::SetVertexAttribute(const char* name)
{
	//unsigned int attribute = glGetAttribLocation(_id, name);
	//CreateAttribute(attribute, 3, 6, 0);
}

void VertexArray::Bind() const
{
	GLCheck(glBindVertexArray(arrayId));
}

void VertexArray::Unbind() const
{
	GLCheck(glBindVertexArray(0));
}

void VertexArray::SetVertexArrayData(const VertexBuffer& vertexBuffer, const VertexBufferLayout& vertexBufferLayout)
{
	Bind();
	vertexBuffer.Bind();
	const std::vector<VertexBufferLayoutElement>& elements = vertexBufferLayout.GetElements();

	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		VertexBufferLayoutElement element = elements[i];
		GLCheck(glEnableVertexAttribArray(i));
		GLCheck(glVertexAttribPointer(i, element.count, element.type, element.isNormalized , vertexBufferLayout.GetStride(), (const void*)offset));
		offset += element.count * VertexBufferLayoutElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Delete()
{
	GLCheck(glDeleteVertexArrays(1, &arrayId));
}
