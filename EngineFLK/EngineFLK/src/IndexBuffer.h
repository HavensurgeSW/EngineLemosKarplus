#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H
#include "Exports.h"
#include "ErrorHandling.h"

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
	
	void Bind();  //both could be const
	void Unbind();
	void Delete();

	unsigned int GetIndexCount() const;
};

#endif