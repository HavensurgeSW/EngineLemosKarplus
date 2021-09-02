#include "Input.h"

#include "glfw3.h"

void Input::pollEvents() {
	glfwPollEvents();
}