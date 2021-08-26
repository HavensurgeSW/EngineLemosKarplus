#include "Renderer.h"
#include "glew.h"
#include "glfw3.h"

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

void Renderer::genBuffers() {
	float positions[6] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f,  0.5f
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
}
