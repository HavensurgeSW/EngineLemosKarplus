#pragma once
#include "Exports.h"

class FLK_API IndexBuffer
{
private:
	unsigned int rendererId;
	unsigned int indexCount;

public:

	IndexBuffer(const unsigned int* data, unsigned int indexCount);
	~IndexBuffer();

	void Bind();  //both could be const
	void Unbind();

	inline unsigned int GetIndexCount() const;
};