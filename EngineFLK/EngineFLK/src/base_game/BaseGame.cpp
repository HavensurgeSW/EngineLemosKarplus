#include "BaseGame.h"

#include "glfw3.h"

#include "utility/error_handling/ErrorHandling.h"
#include "utility/utils/Utils.h"
#include "utility/color/Color.h"
#include "shader/Shader.h"

#include <time.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vertex_buffer/VertexBuffer.h>
#include <index_buffer/IndexBuffer.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
	shader.SetColorUniform(shaderColor);
	shader.Unbind();

	renderer->SetClearColor(Color::RandomColor());

	float increment = 0.05f;
	
	while (!window->ShouldClose())
	{
		renderer->ClearScreen();
		shader.Bind();

		shader.SetColorUniform(shaderColor);

		glm::mat4 transform = glm::mat4(1.0f);

		transform = glm::translate(transform, glm::vec3(-0.5f, -0.5f, 0.0f));                       //
		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));		// MAGIK
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f));								//
		
		shader.SetTransformUniform(transform);

		if (shaderColor.r > 1.0f || shaderColor.r < 0.0f)
		{
			increment *= -1;
		}
		shaderColor.r += increment;

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