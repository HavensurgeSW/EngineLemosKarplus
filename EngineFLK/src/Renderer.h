#pragma once

#include "Window.h"
#include "glew.h"
#include "glfw3.h"

class Renderer {
private:
	Window* _window;

public:
	Renderer();
	~Renderer();

	void swapBuffer();
	void setClearColor(float r, float g, float b, float a);
	void clearScreen();
	void setWindow(Window* window);
	void genBuffers();
};

