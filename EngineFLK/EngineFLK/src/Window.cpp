#include "Window.h"

Window::Window()
{

}

Window::Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	//This constructor wont work unless GLFW is initialized BEFORE calling it, since
	//it uses a glfw method
	window = glfwCreateWindow(width, height, title, monitor, share);	
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

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}
