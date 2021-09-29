#include "BaseGame.h"

#include "glfw3.h"

#include "ErrorHandling.h"
#include "Utils.h"
#include "Color.h"
#include "Shader.h"

#include <time.h>
#include <fstream>
#include <sstream>
#include <string>
#include <VertexBuffer.h>
#include <IndexBuffer.h>

BaseGame::BaseGame()
{
	window = new Window();
	renderer = new Renderer();
	input = new Input();
	collisionManager = new CollisionManager();
	entity = new Entity();
}

BaseGame::~BaseGame()
{
	delete window;
	delete renderer;
	delete input;
	delete collisionManager;
	delete entity;
}

void BaseGame::InitEngine()
{
	srand(time(0));

	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
	}

	window->CreateWindow(800, 600, "Init window.", NULL, NULL);
	if (!window->GetGLFWWindow()) {

		std::cout << "Init Error. Window is null, terminating program." << std::endl;
		Terminate();
	}

	renderer->SetWindow(window);

	renderer->MakeContextCurrent(window);
	renderer->InitGlew();

	renderer->GenerateBuffers();
}

void BaseGame::LaunchGodEngine()
{
	Color shaderColor = Color::RandomColor();
	Shader shader("res/shaders/Basic.shader");
	shader.Bind();

	shader.SetColorUniform("u_Color", shaderColor);
	shader.Unbind();

	//renderer->Unbind(); ????
	renderer->SetClearColor(Color::RandomColor());

	float increment = 0.05f;

	while (!window->ShouldClose())
	{
		renderer->ClearScreen();
		shader.Bind();

		shader.SetColorUniform("u_Color", shaderColor);

		if (shaderColor.r > 1.0f || shaderColor.r < 0.0f)
		{
			increment *= -1;
		}
		shaderColor.r += increment;

		//renderer->DrawTriangle();
		renderer->DrawElement(6); //6 is the size of the indices array
		renderer->SwapBuffer();
		TempInputs(window);
	}
}

void BaseGame::Terminate()
{
	glfwTerminate();
}

void BaseGame::TempInputs(Window* window)
{
	//INPUT DE MOVIMIENTO
	if (input->GetKey(window->GetGLFWWindow(), KeyBoard::KEY_W))
	{
		std::cout << "W" << std::endl;
	}
	if (glfwGetKey(window->GetGLFWWindow(), KeyBoard::KEY_S))
	{
		std::cout << "S" << std::endl;
	}
	if (glfwGetKey(window->GetGLFWWindow(), KeyBoard::KEY_D))
	{
		std::cout << "D" << std::endl;
	}
	if (glfwGetKey(window->GetGLFWWindow(), KeyBoard::KEY_A))
	{
		std::cout << "A" << std::endl;
	}
	

}