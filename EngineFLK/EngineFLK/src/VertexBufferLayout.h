#ifndef VERTEX_BUFFER_LAYOUT_H
#define VERTEX_BUFFER_LAYOUT_H

#include "glew.h"
#include "glfw3.h"

#include <vector>

struct VertexBufferLayoutElement
{
	unsigned int type;
	int count;
	unsigned char isNormalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:
			return 4;

		case GL_UNSIGNED_INT:
			return 4;

		case GL_UNSIGNED_BYTE:
			return 1;

		default:
			break;
		}

		return 0;
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferLayoutElement> elements;
	unsigned int stride;

public:
	VertexBufferLayout();
	~VertexBufferLayout();

	const std::vector<VertexBufferLayoutElement> GetElements() const&;
	unsigned int GetStride() const;

	template<typename T>
	void Push(int count);

	template<>
	void Push<float>(int count);

	template<>
	void Push<unsigned int>(int count);

	template<>
	void Push<unsigned char>(int count); //Unsigned char is basically a byte
};

#endif