#include "BaseGame.h"

BaseGame::BaseGame(){
	myWindow = new Window();
	_renderer = new Renderer();

}

BaseGame::~BaseGame(){
	delete myWindow;
	delete _renderer;
}

void BaseGame::launchGod() {
	/* Initialize the library */
	if (!glfwInit()){
		std::cout << "Error de inicializacion" << std::endl;
	}

	myWindow->setWindow(myWindow->createWindow(800, 600, "Hello World", NULL, NULL));
	_renderer->setWindow(myWindow->getWindow());

	if (!myWindow->getWindow()){
		glfwTerminate();
		std::cout << "Terminate() successful" << std::endl;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(myWindow->getWindow());

	/* Loop until the user closes the window */
	while (!myWindow->shouldClose()){
		_renderer->clear();
		_renderer->swapBuffer();
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