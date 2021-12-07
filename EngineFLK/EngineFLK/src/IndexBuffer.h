#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include "Exports.h"

class FLK_API IndexBuffer
{
private:
	unsigned int bufferId;
	unsigned int indexCount;

public:

	IndexBuffer();
	IndexBuffer(const unsigned int indices[], unsigned int indexCount);
	~IndexBuffer();

	void SetData(const unsigned int indices[], unsigned int indexCount);
	
	void Bind() const;
	void Unbind() const;
	void Delete() const;

	unsigned int GetIndexCount() const;
};

#endif