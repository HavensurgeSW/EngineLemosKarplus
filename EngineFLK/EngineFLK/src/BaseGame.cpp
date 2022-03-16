#include "BaseGame.h"

#include "glfw3.h"

#include "ErrorHandling.h"


BaseGame::BaseGame()
{
	renderer = new Renderer();
	window = new Window();
	input = new Input();
	collisionManager = new CollisionManager();
}

BaseGame::~BaseGame()
{
	delete renderer;
	delete window;
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
	srand(NULL);

	bool initResult = glfwInit();
	if (!initResult)
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
	}

	window->SetWindow(window->CreateWindow(800, 600, "Hello World", NULL, NULL));
	input->SetContextWindow(window);

	if (!window->GetGLFWWindow()) {

		std::cout << "Error. Window is null, terminating." << std::endl;
		Terminate();
	}

	Renderer::GetInstance().SetWindow(window);

	Renderer::GetInstance().MakeContextCurrent(window);

	InitGlew();

	Renderer::GetInstance().SetClearColor(Color::Black());
	Init();
}

void BaseGame::LaunchGod()
{
	while (!window->ShouldClose())
	{
		Renderer::GetInstance().ClearScreen();

		Update(); //FOR SOME REASON (check reason) the Update method MUST be below the ClearScreen() method AND above the SwapBuffers() method.

		Renderer::GetInstance().SwapBuffer();
		input->PollEvents();

		time.UpdateTime();
		time.UpdateFPS();
	}

	Terminate();
}

//Renderer* BaseGame::GetRenderer() const
//{
//	return renderer;
//}

CollisionManager* BaseGame::GetCollisionManager() const
{
	return collisionManager;
}

void BaseGame::Terminate()
{
	DeInit();
	glfwTerminate();
}