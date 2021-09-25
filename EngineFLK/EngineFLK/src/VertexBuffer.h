#pragma once
#include "Exports.h"

class FLK_API VertexBuffer
{
private:
	unsigned int rendererId;

public:

	VertexBuffer();
	VertexBuffer(const void* data, unsigned int byteSize);
	~VertexBuffer();

	void Bind();
	void Unbind();
	//void SetData(const void* data, unsigned int size); //might need it?
};