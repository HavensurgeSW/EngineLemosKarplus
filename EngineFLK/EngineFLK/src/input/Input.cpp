#include "Input.h"

#include "glfw3.h"

void Input::PollEvents() 
{
	glfwPollEvents();
}