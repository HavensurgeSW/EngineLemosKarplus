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
}

void BaseGame::LaunchGod()
{
	srand(time(0));

	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
	}

	window->SetWindow(window->CreateWindow(800, 600, "Hello World", NULL, NULL));

	if (!window->GetWindow()) {

		std::cout << "Error. Window is null, terminating." << std::endl;
		Terminate();
	}

	renderer->SetWindow(window);

	renderer->MakeContextCurrent(window);
	renderer->InitGlew();

	renderer->GenerateBuffers();

	Shader shader("res/shaders/Basic.shader");
	shader.Bind();

	Color shaderColor = Color::RandomColor();
	shader.SetColorUniform("u_Color", shaderColor);
	shader.Unbind();

	//renderer->Unbind(); ????
	renderer->SetClearColor(Color::RandomColor());

	float rValue = shaderColor.r;
	float increment = 0.05f;

	while (!window->ShouldClose())
	{
		renderer->ClearScreen();
		shader.Bind();

		Color color(rValue, shaderColor.g, shaderColor.b, shaderColor.a);
		shader.SetColorUniform("u_Color", color);

		if (rValue > 1.0f || rValue < 0.0f)
		{
			increment *= -1;
		}
		rValue += increment;

		//renderer->DrawTriangle();
		renderer->DrawElement(6); //6 is the size of the indices array
		renderer->SwapBuffer();
		input->PollEvents();
	}

	Terminate();
}

void BaseGame::Terminate()
{
	glfwTerminate();
}