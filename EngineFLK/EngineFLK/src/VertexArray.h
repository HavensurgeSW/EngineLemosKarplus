#pragma once

class VertexArray
{
private:
	unsigned int arrayId;

public:
	VertexArray();
	~VertexArray();

	void GenerateVertexArray();

	void Bind();
	void Unbind();
	void Delete();
};