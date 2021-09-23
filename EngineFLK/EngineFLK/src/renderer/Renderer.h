#pragma once

#include "window/Window.h"
#include "vertex_buffer/VertexBuffer.h"
#include "index_buffer/IndexBuffer.h"
#include "shader/Shader.h"

#include "utility/color/Color.h"

class Renderer
{
private:
	Window* window;


public:
	Renderer();
	~Renderer();

	void InitGlew();
	void SwapBuffer();
	void SetClearColor(Color color);
	void ClearScreen();
	void SetWindow(Window* window);
	void GenerateBuffers(); //genBuffers
	void MakeContextCurrent(Window* window);
	void Unbind();
	void DrawTriangle();
	void DrawElement(int indices);
	void TestDraw(VertexBuffer& vertexBuffer, IndexBuffer& indexBuffer, Shader& shader);
};