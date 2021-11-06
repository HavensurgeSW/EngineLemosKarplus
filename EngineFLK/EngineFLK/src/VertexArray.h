#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

class VertexArray
{
private:
	unsigned int arrayId;

public:
	VertexArray();
	~VertexArray();

	void GenerateVertexArray();
	void SetVertexAttribute(const char* name);
	void Bind();
	void Unbind();
	void Delete();
};

#endif