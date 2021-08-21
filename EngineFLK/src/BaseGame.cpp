#include "BaseGame.h"

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

	/* Loop until the user closes the window */
	while (!_window->shouldClose()){
		_renderer->clear();
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