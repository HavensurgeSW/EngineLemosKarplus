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
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Vector2.h>
#include <Vector3.h>


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

void BaseGame::InitEngine()
{
	Init();
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
}

void BaseGame::LaunchGod()
{
	renderer->GenerateBuffers();

	//Shader shader("res/shaders/Basic.shader");
	shader.CreateShader("res/shaders/Basic.shader");
	shader.Bind();

	Color shaderColor = Color::RandomColor();
	shader.SetColorUniform(shaderColor);
	shader.Unbind();

	renderer->SetClearColor(Color::RandomColor());

	float increment = 0.05f;
	float incrementb = 0.05f;
	float rotationAngle = 15.0f;
	float rotationSpeed = 0.0f;
	float scale = 1.0f;
	Vector2 vec(0.0f, 0.0f);
	Vector3 rotation(0.0f, 0.0f, 1.0f);

	while (!window->ShouldClose())
	{
		Update();

		renderer->ClearScreen();
		shader.Bind();

		glm::mat4 transform = glm::mat4(1.0f);

		transform = glm::translate(transform, glm::vec3(vec.x, vec.y, 0.0f));                                   //
		transform = glm::rotate(transform, rotationSpeed, glm::vec3(rotation.x, rotation.y, rotation.z));		// MAGIK?
		transform = glm::scale(transform, glm::vec3(scale, scale, scale));										//

		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_W))
		{
			vec.y += 0.01f;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_S))
		{
			vec.y -= 0.01f;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_D))
		{
			vec.x += 0.01f;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_A))
		{
			vec.x -= 0.01f;
		}

		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_ENTER))
		{
			scale += 0.01f;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_BACKSPACE))
		{
			scale -= 0.01f;
		}

		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_Q))
		{
			rotationSpeed += 0.1f;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_E))
		{
			rotationSpeed -= 0.1f;
		}

		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_I))
		{
			rotation.x += 0.1f;
			std::cout << "Rotation Angle X: " << rotation.x << std::endl;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_O))
		{
			rotation.y += 0.1f;
			std::cout << "Rotation Angle Y: " << rotation.y << std::endl;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_P))
		{
			rotation.z += 0.1f;
			std::cout << "Rotation Angle Z: " << rotation.z << std::endl;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_J))
		{
			rotation.x -= 0.1f;
			std::cout << "Rotation Angle X: " << rotation.x << std::endl;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_K))
		{
			rotation.y -= 0.1f;
			std::cout << "Rotation Angle Y: " << rotation.y << std::endl;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_L))
		{
			rotation.z -= 0.1f;
			std::cout << "Rotation Angle Z: " << rotation.z << std::endl;
		}
		if (input->GetKey(window->GetWindow(), KeyBoard::KEY_R))
		{
			vec = Vector2::Zero();
			rotationSpeed = 0;
			rotation = Vector3::One();
			scale = 1.0f;
		}
		shader.SetTransformUniform(transform);

		if (shaderColor.r > 1.0f || shaderColor.r < 0.0f)
		{
			increment *= -1;
		}
		if (shaderColor.b > 1.0f || shaderColor.b < 0.0f)
		{
			incrementb *= -1;
		}
		shaderColor.r += increment;
		shaderColor.b += incrementb;
		shader.SetColorUniform(shaderColor);

		renderer->DrawElement(6); //6 is the size of the indices array
		renderer->SwapBuffer();
		input->PollEvents();
		TempInputs(window);
	}

	Terminate();
}

void BaseGame::Terminate()
{
	DeInit();
	glfwTerminate();
}