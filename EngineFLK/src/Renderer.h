#pragma once

#include "Window.h"
#include "GLFW/glfw3.h"

class Renderer {
private:
	Window* _window;

public:
	Renderer();
	~Renderer();

	void clear();
	void swapBuffer();
	void setWindow(Window* window);
};

