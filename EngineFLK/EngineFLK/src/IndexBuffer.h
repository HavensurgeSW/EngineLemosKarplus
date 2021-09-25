#pragma once
#include "Exports.h"
#include "ErrorHandling.h"

class FLK_API IndexBuffer
{
private:
	unsigned int rendererId;
	unsigned int indexCount;

public:

	IndexBuffer();
	IndexBuffer(const unsigned int* data, unsigned int indexCount);
	~IndexBuffer();

	void Bind();  //both could be const
	void Unbind();

	unsigned int GetIndexCount() const;
};