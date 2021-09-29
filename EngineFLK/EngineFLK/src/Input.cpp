#include "Input.h"
#include "glew.h"
#include "glfw3.h"

bool Input::CheckKeyPress(GLFWwindow* contextWindow, KeyBoard _keyBoard, unsigned int type)
{
	return (glfwGetKey(contextWindow, _keyBoard) == type);
}

Input::Input() {}


Input::~Input() {}

bool Input::GetKeyDown(GLFWwindow* contextWindow, KeyBoard _keyBoard)
{
	return CheckKeyPress(contextWindow, _keyBoard, GLFW_REPEAT);
}

bool Input::GetKey(GLFWwindow* contextWindow, KeyBoard _keyBoard)
{
	return CheckKeyPress(contextWindow, _keyBoard, GLFW_PRESS);
}

bool Input::GetKeyUp(GLFWwindow* contextWindow, KeyBoard _keyBoard)
{
	return CheckKeyPress(contextWindow, _keyBoard, GLFW_RELEASE);
}

void Input::PollEvents() 
{
	glfwPollEvents();
}
