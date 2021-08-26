﻿#include "Renderer.h"
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
	const int maxPositions = 6;

	float positions[maxPositions] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f,  0.5f
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, maxPositions * sizeof(float), positions, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //float * 2 implica que cada seccion de memoria del vertice tiene el tama�o de 2 floats. X e Y
	glEnableVertexAttribArray(0); //Antes del Pointer, pero despues de bindear el buffer DICE CHERNO. A checkear?


	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderer::drawTriangle() {
	glDrawArrays(GL_TRIANGLES, 0, 3);

}
