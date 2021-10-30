#include "BaseGame.h"

#include "glfw3.h"

#include "ErrorHandling.h"
#include "Color.h"
#include "Shader.h"

#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Transform.h"


BaseGame::BaseGame()
{
	window = new Window();
	renderer = new Renderer();
	input = new Input();
	collisionManager = new CollisionManager();
}

BaseGame::~BaseGame()
{
	delete window;
	delete renderer;
	delete input;
	delete collisionManager;
	delete triangle;
}

void BaseGame::InitGlew()
{
	glewInit();
	InitErrorHandling();
}

void BaseGame::InitEngine()
{
	Init();
	srand(time(0));
	bool initResult = glfwInit();
	if (!initResult)
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
	}

	window->SetWindow(window->CreateWindow(800, 600, "Hello World", NULL, NULL));
	input->SetContextWindow(window);

	if (!window->GetWindow()) {

		std::cout << "Error. Window is null, terminating." << std::endl;
		Terminate();
	}

	renderer->SetWindow(window);

	renderer->MakeContextCurrent(window);

	InitGlew();
	
	renderer->SetClearColor(Color::RandomColor());
}

void BaseGame::LaunchGod()
{
	shader.CreateShader("res/shaders/Basic.shader");

	triangle = new Shape(renderer, shader, ShapeType::TRIANGLE, true);
	quad = new Shape(renderer, shader, ShapeType::QUAD, true);
	otherQuad = new Shape(renderer, shader, ShapeType::QUAD, true);

	triangle->SetColor(Color::RandomColor());  //
	quad->SetColor(Color::RandomColor());	   //Not working correctly, shader reference error?
	otherQuad->SetColor(Color::RandomColor()); //

	Vector2 trianglePosition(0.0f, 0.0f);
	float triangleRotationSpeed = 0.0f;
	Vector3 triangleRotation(0.0f, 0.0f, 1.0f);
	Vector2 quadPosition(0.5f, 0.5f);
	float quadRotationSpeed = 0.0f;
	Vector3 quadRotation(0.0f, 0.0f, 1.0f);

	float scale = 0.3f;

	while (!window->ShouldClose())
	{
		Update();
		renderer->ClearScreen();
		triangle->Draw();
		quad->Draw();
		otherQuad->Draw();

		triangle->transform.SetRotation(triangleRotationSpeed, triangleRotation);
		quad->transform.SetRotation(quadRotationSpeed, quadRotation);
		triangle->transform.SetPosition(trianglePosition);
		quad->transform.SetPosition(quadPosition);

		triangle->transform.SetScale(scale);
		quad->transform.SetScale(scale);
		otherQuad->transform.SetScale(scale);
		
		if (Input::GetKey(KeyCode::W))
		{
			trianglePosition.y += 0.01f;
		}
		if (Input::GetKey(KeyCode::S))
		{
			trianglePosition.y -= 0.01f;
		}
		if (Input::GetKey(KeyCode::D))
		{
			trianglePosition.x += 0.01f;
		}
		if (Input::GetKey(KeyCode::A))
		{
			trianglePosition.x -= 0.01f;
		}
		if (Input::GetKey(KeyCode::Q))
		{
			triangleRotationSpeed += 0.01f;
		}
		if (Input::GetKey(KeyCode::E))
		{
			triangleRotationSpeed -= 0.01f;
		}

		if (Input::GetKey(KeyCode::UP))
		{
			quadPosition.y += 0.01f;
		}
		if (Input::GetKey(KeyCode::DOWN))
		{
			quadPosition.y -= 0.01f;
		}
		if (Input::GetKey(KeyCode::RIGHT))
		{
			quadPosition.x += 0.01f;
		}
		if (Input::GetKey(KeyCode::LEFT))
		{
			quadPosition.x -= 0.01f;
		}
		if (Input::GetKey(KeyCode::NUMPAD_1))
		{
			quadRotationSpeed += 0.01f;
		}
		if (Input::GetKey(KeyCode::NUMPAD_3))
		{
			quadRotationSpeed -= 0.01f;
		}

		renderer->SwapBuffer();
		input->PollEvents();
	}

	Terminate();
}

void BaseGame::Terminate()
{
	DeInit();
	glfwTerminate();
}