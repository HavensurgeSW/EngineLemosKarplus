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

void Renderer::MakeContextCurrent(Window* window)
{
	glfwMakeContextCurrent(window->GetWindow());
	glfwSwapInterval(1); //synchrinizes with our vSync
}

void Renderer::GenerateBuffers(float vertices[], int maxVertices, unsigned int indices[], int maxIndices)
{
	//vertexArray.GenerateVertexArray();
	//vertexBuffer.SetData(vertices, maxVertices);
	//indexBuffer.SetData(indices, maxIndices);
}

void Renderer::Draw(Shader& shader, int indexCount)
{
	//shader.SetVertexAttributes("position");
	shader.SetVertexAttributes("position");
	shader.SetColorAttributes("color");

	GLCheck(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

	//vertexArray.Unbind();
	//vertexBuffer.Unbind();
	//indexBuffer.Unbind();
	//shader.Unbind();
}

void Renderer::UnbindBuffers()
{
	//vertexArray.Unbind();
	//vertexBuffer.Unbind();
	//indexBuffer.Unbind();
	//GLCheck(glUseProgram(0));
}
