#include "BaseGame.h"

BaseGame::BaseGame()
{
	myWindow = new Window();
	_renderer = new Renderer();
}

BaseGame::~BaseGame()
{
	delete myWindow;
	delete _renderer;
}

void BaseGame::launchGod() 
{
	/* Initialize the library */
	if (!glfwInit()) 
	{
		std::cout << "Error de inicializacion" << std::endl;
	}

	_window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);

	if (!_window) 
	{
		glfwTerminate();
		std::cout << "Terminate() successful" << std::endl;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(_window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(_window)) 
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}

	glfwTerminate();
}

void BaseGame::launchGodTest() 
{
	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "Error de inicializacion" << std::endl;
	}

	myWindow->setWindow(myWindow->createWindow(800, 600, "Hello World", NULL, NULL));

	if (!myWindow->getWindow())
	{
		glfwTerminate();
		std::cout << "Terminate() successful" << std::endl;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(myWindow->getWindow());

	/* Loop until the user closes the window */
	while (!myWindow->shouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(myWindow->getWindow());
		glfwPollEvents();
	}

	glfwTerminate();
}