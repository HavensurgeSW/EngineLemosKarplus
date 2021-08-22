#include "Renderer.h"

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

void Renderer::swapBuffer() {
	glfwSwapBuffers(_window->getWindow());
}

//Sets background color with RGBA values
void Renderer::setClearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}

void Renderer::clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::setWindow(Window* window) {
	_window = window;
}
