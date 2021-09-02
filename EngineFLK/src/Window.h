#pragma once

#include "glew.h"
#include "glfw3.h"

class Window 
{
private:
	GLFWwindow* window;

public:
	Window();
	~Window();

	GLFWwindow* CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void SetWindow(GLFWwindow* window);
	GLFWwindow* GetWindow();
	int ShouldClose();
};