#include "VertexArray.h"

#include "glew.h"
#include "ErrorHandling.h"

VertexArray::VertexArray()
{

}

VertexArray::~VertexArray()
{

}

void VertexArray::GenerateVertexArray()
{
	GLCheck(glGenVertexArrays(1, &arrayId));
	GLCheck(glBindVertexArray(arrayId));
}

void VertexArray::Bind()
{
	GLCheck(glBindVertexArray(arrayId));
}

void VertexArray::Unbind()
{
	GLCheck(glBindVertexArray(0));
}

void VertexArray::Delete()
{
	GLCheck(glDeleteVertexArrays(1, &arrayId));
}
