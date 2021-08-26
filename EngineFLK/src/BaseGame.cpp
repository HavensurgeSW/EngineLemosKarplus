#include "BaseGame.h"

#include "glfw3.h"
#include <time.h>

BaseGame::BaseGame() {
	_window = new Window();
	_renderer = new Renderer();
}

BaseGame::~BaseGame() {
	delete _window;
	delete _renderer;
}

void BaseGame::launchGod() {
	/* Initialize the library */
	srand(time(NULL));
	if (!glfwInit()){
		std::cout << "Error de inicializacion" << std::endl;
	}

	_window->setWindow(_window->createWindow(800, 600, "Hello World", NULL, NULL));
	_renderer->setWindow(_window);

	if (!_window->getWindow()){
		terminate();
		std::cout << "Terminate() successful" << std::endl;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(_window->getWindow());

	//I FUCKING HATE RANDOM FLOAT VALUES HOW CAN THIS BE SO HARD ON C++
	float random = static_cast<float>(((std::rand()) % 100) + 1) / 100.0f;
	std::cout << random;

	_renderer->setClearColor(1.0f, 0.5f, 0.2f, 1.0f);

	/* Loop until the user closes the window */
	while (!_window->shouldClose()){
		_renderer->clearScreen();
		_renderer->swapBuffer();
		glfwPollEvents();
	}

	terminate();
}

void BaseGame::launchGodTest() 
{
	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "Error de inicializacion" << std::endl;
	}

	_window->setWindow(_window->createWindow(800, 600, "Hello World", NULL, NULL));

	if (!_window->getWindow())
	{
		terminate();
		std::cout << "Terminate() successful" << std::endl;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(_window->getWindow());

	/* Loop until the user closes the window */
	while (!_window->shouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(_window->getWindow());
		glfwPollEvents();
	}

	terminate();
}

void BaseGame::terminate() {
	glfwTerminate();
}