#pragma once

#include "Window.h"
#include "GLFW/glfw3.h"

class Renderer{
private:
	GLFWwindow* _window;

public:
	void clear();
	void swapBuffer();
};

