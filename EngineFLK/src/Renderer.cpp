#include "Renderer.h"

void Renderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::swapBuffer(){
	glfwSwapBuffers(_window);
}
