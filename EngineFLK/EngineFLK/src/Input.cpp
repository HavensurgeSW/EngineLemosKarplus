#include "Input.h"

#include <iostream>

#include "glfw3.h"
#include "Vector2.h"

Window* Input::window = NULL;

Input::Input() 
{

}

Input::~Input() 
{

}


bool Input::GetMouseButtonDown(MouseButton mouseButton)  //LITERALLY WONT WORK
{
	return CheckMouseButtonPress(mouseButton, KeyState::GET_KEY_DOWN);
}

bool Input::GetMouseButton(MouseButton mouseButton)
{
	return CheckMouseButtonPress(mouseButton, KeyState::GET_KEY);
}

bool Input::GetMouseButtonUp(MouseButton mouseButton) //LITERALLY WONT WORK
{
	return CheckMouseButtonPress(mouseButton, KeyState::GET_KEY_UP);
}


Vector2 Input::GetMousePosition()
{
	double xPos;
	double yPos;

	glfwGetCursorPos(window->GetGLFWWindow(), &xPos, &yPos);

	return Vector2(static_cast<float>(xPos), static_cast<float>(yPos));
}


bool Input::GetKeyDown(KeyCode keycode) //LITERALLY WONT WORK
{
	return CheckKeyPress(keycode, GET_KEY_DOWN);
}

bool Input::GetKey(KeyCode keycode)
{
	return CheckKeyPress(keycode, GET_KEY);
}

bool Input::GetKeyUp(KeyCode keycode) //LITERALLY WONT WORK
{
	return CheckKeyPress(keycode, GET_KEY_UP);
}


void Input::SetContextWindow(Window* contextWindow)
{
	window = contextWindow;
	if (window != NULL) 
	{
		glfwSetKeyCallback(window->GetGLFWWindow(), KeyInputCallback); //a method KeyInputCallback is called on key input
	}
}

void Input::PollEvents()
{
	glfwPollEvents();
}


bool Input::CheckKeyPress(KeyCode keycode, int type)
{
	return glfwGetKey(window->GetGLFWWindow(), keycode) == type;
}

bool Input::CheckMouseButtonPress(MouseButton mouseButton, int type)
{
	return glfwGetMouseButton(window->GetGLFWWindow(), mouseButton) == type;
}


void Input::KeyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout <<"Key " << key << " pressed." << std::endl;
}