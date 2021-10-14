#include "Renderer.h"

#include "glew.h"
#include "glfw3.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ErrorHandling.h"

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

void Renderer::SwapBuffer()
{
	glfwSwapBuffers(window->GetWindow());
}

void Renderer::SetClearColor(Color color)
{
	GLCheck(glClearColor(color.r, color.g, color.b, color.a));
}

void Renderer::ClearScreen()
{
	GLCheck(glClear(GL_COLOR_BUFFER_BIT));
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

	//float texCoords[] = {
	//	-0.5f, -0.5f,
	//	 0.5f, -0.5f,
	//	 0.5f,  0.5f,
	//	-0.5f,  0.5f
	//};

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	//float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	const int maxIndices = 6;
	unsigned int indices[maxIndices] = //Triangle connections
	{
		0, 1, 2, //triangle 1
		2, 3, 0  //triangle 2 
	};

	VertexBuffer vertexBuffer(positions, maxPositions * sizeof(float));

	GLCheck(glEnableVertexAttribArray(0)); //enables or "turns on" the specified attribute
	GLCheck(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));  //specifies the location of the attribute of the vertex and its format (stride, offset, amount of values dpending on the atribute, etc)
	//float * 2 implies that each memory section of the vertex has the size of 2 floats (X and Y)

	IndexBuffer indexBuffer(indices, maxIndices);
	indexBuffer.Bind();
}

void Renderer::MakeContextCurrent(Window* window)
{
	glfwMakeContextCurrent(window->GetWindow());
	glfwSwapInterval(1); //synchrinizes with our vSync
}

void Renderer::Unbind()
{
	GLCheck(glUseProgram(0));
	GLCheck(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void Renderer::DrawTriangle()
{
	GLCheck(glDrawArrays(GL_TRIANGLES, 0, 6));
}

// Used to draw an element utilizing indices
void Renderer::DrawElement(int indices)
{
	GLCheck(glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr));
	//To test the error handling, just change the GL_UNSIGNED_INT to GL_INT and watch the magic
}

void Renderer::Draw(Shader shader)
{

}