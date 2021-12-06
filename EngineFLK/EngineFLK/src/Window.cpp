#include "Window.h"

#include <iostream>

Window::Window()
{

}

Window::Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	//This constructor wont work unless GLFW is initialized BEFORE calling it, since
	//it uses a glfw method

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	glfwWindow = glfwCreateWindow(width, height, title, monitor, share);
}

Window::~Window()
{

}

GLFWwindow* Window::CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	return glfwCreateWindow(width, height, title, monitor, share);
}

void Window::SetWindow(GLFWwindow* glfwWindow)
{
	this->glfwWindow = glfwWindow;
}

GLFWwindow* Window::GetGLFWWindow()
{
	return glfwWindow;
}

void Window::DestroyWindow()
{
	glfwDestroyWindow(glfwWindow);
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(glfwWindow);
}
