#include "Input.h"

#include "glfw3.h"

Input::Input() 
{
	window = new Window();
}

Input::~Input() 
{

}


bool Input::CheckKeyPress(KeyCode keycode, int type)
{
	return (glfwGetKey(window->GetWindow(), keycode) == type);
}

bool Input::CheckMouseButtonPress(MouseButton mouseButton, int type)
{
	return glfwGetMouseButton(window->GetWindow(), mouseButton) == GET_KEY_DOWN;
}


bool Input::GetMouseButtonPressed(MouseButton button)
{
	return glfwGetMouseButton(window->GetWindow(), button) == GET_KEY_DOWN;
}

bool Input::GetKeyDown(KeyCode keycode)
{
	return CheckKeyPress(keycode, GET_KEY_DOWN);
}

bool Input::GetKey(KeyCode keycode)
{
	return CheckKeyPress(keycode, GET_KEY);
}

bool Input::GetKeyUp(KeyCode keycode)
{
	return CheckKeyPress(keycode, GET_KEY_UP);
}


void Input::SetContextWindow(Window* window)
{
	this->window = window;
}

void Input::PollEvents()
{
	glfwPollEvents();
}