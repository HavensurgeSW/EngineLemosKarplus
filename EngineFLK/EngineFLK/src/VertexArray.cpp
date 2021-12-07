#include "VertexArray.h"

#include "glew.h"
#include "VertexBuffer.h"
#include "ErrorHandling.h"

VertexArray::VertexArray()
{
	GLCheck(glGenVertexArrays(1, &arrayId));
}

VertexArray::~VertexArray()
{
	GLCheck(glDeleteVertexArrays(1, &arrayId));
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

void VertexArray::SetData(const VertexBuffer& vertexBuffer)
{
	Bind();
	vertexBuffer.Bind();

	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		const VertexBufferLayoutElement& element = elements[i];
		GLCheck(glEnableVertexAttribArray(i));
		GLCheck(glVertexAttribPointer(i, element.count, element.type, element.isNormalized, stride, (const void*)offset));
		offset += element.count * sizeof(element.type);
	}
	vertexBuffer.Unbind();
	Unbind();
}

void VertexArray::Delete()
{
	GLCheck(glDeleteVertexArrays(1, &arrayId));
}

template<typename T>
void VertexArray::Push(int count)
{
	static_assert(false);
}

template<>
void VertexArray::Push<float>(int count)
{
	elements.push_back({ GL_FLOAT, count, GL_FALSE });
	stride += count * sizeof(GL_FLOAT);
}

template<>
void VertexArray::Push<unsigned int>(int count)
{
	elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
	stride += count * sizeof(GL_UNSIGNED_INT);
}

template<>
void VertexArray::Push<unsigned char>(int count)
{
	elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
	stride += count * sizeof(GL_UNSIGNED_BYTE);
}