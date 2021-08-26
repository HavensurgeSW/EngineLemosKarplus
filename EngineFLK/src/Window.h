#pragma once


class Window {
private:
	GLFWwindow* _window;

public:
	Window();
	~Window();

	GLFWwindow* createWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void setWindow(GLFWwindow* window);
	GLFWwindow* getWindow();
	int shouldClose();
};