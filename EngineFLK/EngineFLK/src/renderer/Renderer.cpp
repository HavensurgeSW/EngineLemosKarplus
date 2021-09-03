#include <iostream>

#include "Renderer.h"
#include "glew.h"
#include "glfw3.h"

Renderer::Renderer() 
{

}

Renderer::~Renderer() 
{

}

void Renderer::InitGlew() 
{
	glewInit();
}

void Renderer::SwapBuffer() 
{
	glfwSwapBuffers(window->GetWindow());
}

//Sets background color with RGBA values
void Renderer::SetClearColor(float r, float g, float b, float a) 
{
	glClearColor(r, g, b, a);
}

void Renderer::ClearScreen() 
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SetWindow(Window* window) 
{
	this->window = window;
}

void Renderer::GenerateBuffers() 
{
	const int maxPositions = 6;

	float positions[maxPositions] = 
	{
		-0.5f, -0.5f, //vertex 1
		 0.0f,  0.5f, //vertex 2
		 0.5f, -0.5f  //vertex 3
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, maxPositions * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //float * 2 implica que cada seccion de memoria del vertice tiene el tama�o de 2 floats. X e Y
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderer::MakeContextCurrent(Window* window) 
{
	glfwMakeContextCurrent(window->GetWindow());
}

void Renderer::DrawTriangle() 
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
