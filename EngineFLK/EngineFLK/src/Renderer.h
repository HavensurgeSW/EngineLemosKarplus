#ifndef RENDERER_H
#define RENDERER_H

#include "Exports.h"

#include "Window.h"
#include "Shader.h"
#include "Color.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

class FLK_API Renderer
{
private:
	Window* window;

public:
	Renderer();
	~Renderer();

	void SwapBuffer();
	void SetClearColor(Color color);
	void ClearScreen();
	void SetWindow(Window* window);
	void MakeContextCurrent(Window* window);
	void GenerateBuffers(float vertices[], int maxVertices, unsigned int indices[], int maxIndices);
	void Draw(Shader& shader, int indexCount);
	void UnbindBuffers();
};

#endif