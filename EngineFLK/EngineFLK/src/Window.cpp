#include "Window.h"

Window::Window()
{
	glfwWindow = glfwCreateWindow(800, 600, "Fallback Window Text", NULL, NULL);
}

Window::Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	glfwWindow = glfwCreateWindow(width, height, title, monitor, share);
}

Window::~Window()
{

}

void Window::CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	glfwWindow = glfwCreateWindow(width, height, title, monitor, share);
}

void Window::SetWindow(GLFWwindow* glfwWindow)
{
	this->glfwWindow = glfwWindow;
}

GLFWwindow* Window::GetGLFWWindow()
{
	return glfwWindow;
}

int Window::ShouldClose()
{
	return glfwWindowShouldClose(glfwWindow);
}
