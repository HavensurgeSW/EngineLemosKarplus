#include "Window.h"

Window::Window(){

}

Window::~Window() {

}

GLFWwindow* Window::createWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
	return glfwCreateWindow(width, height, title, monitor, share);
}

void Window::setWindow(GLFWwindow* window){
	_window = window;
}

GLFWwindow* Window::getWindow() {
	return _window;
}

int Window::shouldClose() {
	return glfwWindowShouldClose(_window);
}
