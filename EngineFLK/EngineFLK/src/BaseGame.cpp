﻿#include "BaseGame.h"

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
	//delete triangle;
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
	//spriteShader.CreateShader("res/shaders/Sprite.shader");

	Shader triangleShader("res/shaders/Shape.shader");

	Shape triangle(renderer, triangleShader, ShapeType::TRIANGLE);
	triangle.SetColor(Color::Red());

	Shader enanoShader("res/shaders/Sprite.shader");
	Sprite enano(renderer, enanoShader, ShapeType::QUAD);
	enano.SetTexture("res/textures/EnanoBostero.png");
	enano.SetColor(Color::White());

	Shader illuminatiShader("res/shaders/Sprite.shader");
	Sprite illuminati(renderer, illuminatiShader, ShapeType::QUAD);
	illuminati.SetTexture("res/textures/Illuminati.png");
	illuminati.SetColor(Color::Green());

	Shader rockShader("res/shaders/Sprite.shader");
	Sprite rock(renderer, rockShader, ShapeType::QUAD);
	rock.SetTexture("res/textures/TheRock.png");
	rock.SetColor(Color::Red());

	Vector2 trianglePosition(0.0f, -0.5f);
	float triangleRotationSpeed = -3.14f;
	Vector3 triangleRotation(0.0f, 0.0f, 1.0f);
	Vector2 quadPosition(0.0f, 0.5f);
	float quadRotationSpeed = 0.0f;
	Vector3 quadRotation(0.0f, 0.0f, 1.0f);

	float scale = 0.6f;

	while (!window->ShouldClose())
	{
		Update();
		renderer->ClearScreen();
		
		triangle.transform.SetPosition(trianglePosition);
		triangle.transform.SetRotation(triangleRotationSpeed, triangleRotation);
		triangle.transform.SetScale(scale);
		triangle.Draw();

		illuminati.transform.SetPosition(quadPosition);
		illuminati.transform.SetRotation(quadRotationSpeed, quadRotation);
		illuminati.transform.SetScale(scale);
		illuminati.Draw();
		
		enano.transform.SetPosition(0.7f, 0, 0);
		enano.transform.SetScale(scale);
		enano.Draw();
		
		rock.transform.SetPosition(-0.7f, 0, 0);
		rock.transform.SetScale(scale);
		rock.Draw();

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
			std::cout << triangleRotationSpeed << std::endl;
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