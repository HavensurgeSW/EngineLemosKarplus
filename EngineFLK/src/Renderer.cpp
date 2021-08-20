#include "Renderer.h"

Renderer::Renderer(){

}

Renderer::~Renderer()
{

}

void Renderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::swapBuffer()
{
	glfwSwapBuffers(_window);
}

void Renderer::setWindow(GLFWwindow* win){
	_window = win;
}
