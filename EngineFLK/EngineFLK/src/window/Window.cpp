#include "Window.h"

Window::Window()
{

}

Window::~Window() 
{

}

GLFWwindow* Window::CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) 
{
	return glfwCreateWindow(width, height, title, monitor, share);
}

void Window::SetWindow(GLFWwindow* window)
{
	this->window = window;
}

GLFWwindow* Window::GetWindow() 
{
	return window;
}

int Window::ShouldClose() 
{
	return glfwWindowShouldClose(window);
}
