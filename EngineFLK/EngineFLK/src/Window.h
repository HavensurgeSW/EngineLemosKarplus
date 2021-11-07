#ifndef WINDOW_H
#define WINDOW_H

#include "Exports.h"
#include "LibIncludes.h"

class FLK_API Window
{
private:
	GLFWwindow* window;

public:
	Window();
	Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	~Window();

	GLFWwindow* CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void SetWindow(GLFWwindow* window);
	GLFWwindow* GetWindow();
	bool ShouldClose();
};

#endif