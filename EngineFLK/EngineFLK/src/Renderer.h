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
	static Renderer instance;

public:
	Renderer();
	~Renderer();

	Renderer(const Renderer&) = delete; //forces the user to reference the singleton, not copy it

	void SwapBuffer();
	void SetClearColor(Color color);
	void ClearScreen();
	void SetWindow(Window* window);
	void MakeContextCurrent(Window* window);

	static Renderer& GetInstance();

	void Draw(Shader& shader, const Transform& transform, const VertexArray& vertexArray, const VertexBuffer& vertexBuffer, IndexBuffer& indexBuffer);
};

#endif