#pragma once

#include "Exports.h"

#include "Window.h"
#include "Shader.h"
#include "Shape.h"

#include "Color.h"

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
	void GenerateBuffers(); //genBuffers
	void MakeContextCurrent(Window* window);
	void DrawTriangle();
	void DrawElement(int indices);
	void Draw(Shape& shape);
};