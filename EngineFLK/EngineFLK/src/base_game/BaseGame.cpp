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
#include <utility/vector2/Vector2.h>

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

void BaseGame::TempInputs(Window* window)
{
	glm::mat4 transform = glm::mat4(1.0f);
	float rotationAngle = 0.0f;
	float scale = 1.0f;
	Vector2 vec(0.0f, 0.0f);

	transform = glm::translate(transform, glm::vec3(vec.x, vec.y, 1));
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, rotationAngle));
	transform = glm::scale(transform, glm::vec3(scale, scale, scale));

	shader.SetTransformUniform(transform);

	if (input->GetKey(window->GetWindow(), KeyBoard::KEY_W))
	{
		vec.y += 20.0f;
		std::cout << "W" << std::endl;
	}
	if (glfwGetKey(window->GetWindow(), KeyBoard::KEY_S))
	{
		std::cout << "S" << std::endl;
	}
	if (glfwGetKey(window->GetWindow(), KeyBoard::KEY_D))
	{
		std::cout << "D" << std::endl;
	}
	if (glfwGetKey(window->GetWindow(), KeyBoard::KEY_A))
	{
		std::cout << "A" << std::endl;
	}
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

	//Shader shader("res/shaders/Basic.shader");
	shader.CreateShader("res/shaders/Basic.shader");
	shader.Bind();

	Color shaderColor = Color::RandomColor();
	shader.SetColorUniform(shaderColor);
	shader.Unbind();

	renderer->SetClearColor(Color::RandomColor());

	float increment = 0.05f;
	float rotationAngle = 0.0f;
	float scale = 1.0f;
	Vector2 vec(-0.5f, -0.5f);

	
	while (!window->ShouldClose())
	{
		renderer->ClearScreen();
		shader.Bind();

		shader.SetColorUniform(shaderColor);
		glm::mat4 transform = glm::mat4(1.0f);

		transform = glm::translate(transform, glm::vec3(vec.x,vec.y ,0.0f));                       //
		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));		// MAGIK
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f));			

		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_W))
		{
			vec.y += 0.01f;
			std::cout << "W" << std::endl;
		}
		if (glfwGetKey(window->GetWindow(), KeyBoard::KEY_S))
		{
			vec.y -= 0.01f;
			std::cout << "S" << std::endl;
		}
		if (glfwGetKey(window->GetWindow(), KeyBoard::KEY_D))
		{
			vec.x += 0.01f;
			std::cout << "D" << std::endl;
		}
		if (glfwGetKey(window->GetWindow(), KeyBoard::KEY_A))
		{
			vec.x -= 0.01f;
			std::cout << "A" << std::endl;
		}
		
		shader.SetTransformUniform(transform);

		if (shaderColor.r > 1.0f || shaderColor.r < 0.0f)
		{
			increment *= -1;
		}
		shaderColor.r += increment;

		renderer->DrawElement(6); //6 is the size of the indices array
		renderer->SwapBuffer();
		input->PollEvents();
		TempInputs(window);

	}

	Terminate();
}

void BaseGame::Terminate()
{
	glfwTerminate();
}