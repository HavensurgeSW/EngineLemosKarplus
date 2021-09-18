#include "Renderer.h"

#include "glew.h"
#include "glfw3.h"

#include "utility/error_handling/ErrorHandling.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Renderer::Renderer() 
{

}

Renderer::~Renderer() 
{

}

void Renderer::InitGlew() 
{
	glewInit();
	InitErrorHandling();
}

void Renderer::SwapBuffer() 
{
	glfwSwapBuffers(window->GetWindow());
}

void Renderer::SetClearColor(Color color) 
{
	glClearColor(color.r, color.g, color.b, color.a);
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
	const int maxPositions = 8;

	float positions[maxPositions] = //Vertices
	{
		-0.5f, -0.5f, //vertex 0
		 0.5f, -0.5f, //vertex 1
		 0.5f,  0.5f, //vertex 2
		-0.5f,  0.5f  //vertex 3 for square
	};

	vector<float> positions2(maxPositions);
	for (int i = 0; i < maxPositions; i++)
	{
		positions2[i] = positions[i];
	}
	//Intento fallido de usar Vectores para tener acceso a algoritmos

	const int maxIndices = 6;
	unsigned int indices[maxIndices] = //Triangle connections
	{
		0, 1, 2, //triangle 1
		2, 3, 0  //triangle 2
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, maxPositions * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //float * 2 implica que cada seccion de memoria del vertice tiene el tama�o de 2 floats. X e Y


	unsigned int indexBufferObject;
	glGenBuffers(1, &indexBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);	
}

void Renderer::MakeContextCurrent(Window* window) 
{
	glfwMakeContextCurrent(window->GetWindow());
	glfwSwapInterval(1); //synchrinizes with our vSync
}

void Renderer::Unbind()
{
	glUseProgram(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Renderer::DrawTriangle() 
{
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

// Used to draw an element utilizing indices
void Renderer::DrawElement(int indices) 
{
	GLCheck(glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);)
	//To test the error handling, just change the GL_UNSIGNED_INT to GL_INT and watch the magic
}