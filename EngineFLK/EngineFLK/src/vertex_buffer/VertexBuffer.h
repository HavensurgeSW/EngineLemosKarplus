#pragma once

class VertexBuffer
{
private:
	unsigned int rendererId;

public:

	VertexBuffer(const void* data, unsigned int byteSize);
	~VertexBuffer();

	void Bind();
	void Unbind();
	//void SetData(const void* data, unsigned int size); //might need it?
};