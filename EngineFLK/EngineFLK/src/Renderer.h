#pragma once

#include "Exports.h"

#include "Window.h"
#include "Shader.h"

#include "Color.h"

class FLK_API Renderer
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
	void Draw(Shader shader); //agregar mas datos
};