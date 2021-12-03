#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "Exports.h"

#include "VertexBuffer.h"

#include <vector>

struct FLK_API VertexBufferLayoutElement
{
	unsigned int type;
	int count;
	unsigned char isNormalized;
};


class FLK_API VertexArray
{
private:
	unsigned int arrayId;
	std::vector<VertexBufferLayoutElement> elements;
	unsigned int stride;

public:
	VertexArray();
	~VertexArray();

	void SetData(const VertexBuffer& vertexBuffer);
	void SetVertexAttribute(const char* name);

	void Bind() const;
	void Unbind() const;
	void Delete();

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