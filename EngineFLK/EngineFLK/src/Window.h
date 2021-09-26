#pragma once

#include "Exports.h"
#include "glew.h"
#include "glfw3.h"
#include "Exports.h"

class FLK_API Window
{
private:
	GLFWwindow* glfwWindow;

public:
	Window();
	Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	~Window();

	void CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void SetWindow(GLFWwindow* glfwWindow);
	GLFWwindow* GetGLFWWindow();
	int ShouldClose();
};