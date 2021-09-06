#pragma once

#include "window/Window.h"
#include "glfw3.h"
#include "glew.h"

class Renderer 
{
private:
	Window* window;

public:
	Renderer();
	~Renderer();

	void InitGlew();
	void SwapBuffer();
	void SetClearColor(float r, float g, float b, float a);
	void ClearScreen();
	void SetWindow(Window* window);
	void GenerateBuffers(); //genBuffers
	void MakeContextCurrent(Window* window);
	void DrawTriangle();
	void DrawElement(int indices);
};
