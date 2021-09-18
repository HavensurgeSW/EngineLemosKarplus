#pragma once

#include "window/Window.h"

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
};