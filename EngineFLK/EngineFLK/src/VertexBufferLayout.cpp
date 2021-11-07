#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout()
{
	stride = 0;
}

VertexBufferLayout::~VertexBufferLayout()
{

}


const std::vector<VertexBufferLayoutElement> VertexBufferLayout::GetElements() const&
{
	return elements;
}

unsigned int VertexBufferLayout::GetStride() const
{
	return stride;
}


template<typename T>
void VertexBufferLayout::Push(int count)
{
	static_assert(false);
}

template<>
void VertexBufferLayout::Push<float>(int count)
{
	elements.push_back( {GL_FLOAT, count, GL_FALSE } );
	stride += count * VertexBufferLayoutElement::GetSizeOfType(GL_FLOAT);
}

template<>
void VertexBufferLayout::Push<unsigned int>(int count)
{
	elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
	stride += count * VertexBufferLayoutElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::Push<unsigned char>(int count)
{
	elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
	stride += count * VertexBufferLayoutElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}