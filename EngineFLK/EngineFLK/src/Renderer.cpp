#include "Renderer.h"

#include "LibIncludes.h"

#include "ErrorHandling.h"

Renderer Renderer::instance;

Renderer::Renderer()
{
	//instance = *this;
}

Renderer::~Renderer()
{

}

void Renderer::SwapBuffer()
{
	glfwSwapBuffers(window->GetGLFWWindow());
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
	glfwMakeContextCurrent(window->GetGLFWWindow());
	glfwSwapInterval(1); //synchrinizes with our vSync
}

Renderer& Renderer::GetInstance()
{
	return instance;
}

void Renderer::Draw(Shader& shader, const Transform& transform, const VertexArray& vertexArray, const VertexBuffer& vertexBuffer, IndexBuffer& indexBuffer)
{
	shader.Bind();
	vertexArray.Bind();
	vertexBuffer.Bind();
	indexBuffer.Bind();

	shader.SetTransformUniform(transform);
	GLCheck(glDrawElements(GL_TRIANGLES, indexBuffer.GetIndexCount(), GL_UNSIGNED_INT, nullptr));
	
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	indexBuffer.Unbind();
	shader.Unbind();
}