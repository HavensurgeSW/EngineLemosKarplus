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
}

void BaseGame::InitGlew()
{
	glewInit();
	InitErrorHandling();
}

void BaseGame::InitEngine()
{
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
	Init();
}

void BaseGame::LaunchGod()
{
	while (!window->ShouldClose())
	{
		renderer->ClearScreen();

		Update(); //FOR SOME REASON (check reason) the Update method MUST be below the ClearScreen() method AND above the SwapBuffers() method.

		renderer->SwapBuffer();
		input->PollEvents();
	}

	Terminate();
}

Renderer* BaseGame::GetRenderer() const
{
	return renderer;
}

CollisionManager* BaseGame::GetCollisionManager() const
{
	return collisionManager;
}

void BaseGame::Terminate()
{
	DeInit();
	glfwTerminate();
}