#pragma once

#include "Window.h"
#include "glfw3.h"
#include "glew.h"

class Renderer {
private:
	Window* _window;

public:
	Renderer();
	~Renderer();

	void initGlew();
	void swapBuffer();
	void setClearColor(float r, float g, float b, float a);
	void clearScreen();
	void setWindow(Window* window);
	void genBuffers();
	void makeContextCurrent(Window* window);
	void drawTriangle();
};
