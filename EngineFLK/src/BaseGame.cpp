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

	srand(time(NULL));

	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "Error de inicializacion" << std::endl;
	}

	_window->setWindow(_window->createWindow(800, 600, "Hello World", NULL, NULL));

	if (!_window->getWindow()) {
		std::cout << "Error. Window is null, terminating." << std::endl;
		terminate();
	}

	_renderer->setWindow(_window);
	/* Make the window's context current */
	_renderer->makeContextCurrent(_window);
	_renderer->initGlew();
	_renderer->genBuffers();

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main(){\n"
		"gl_Position = position;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main(){\n"
		"color = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n";

	unsigned int shader = createShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	//----------------------------
	//haha pretty background colors go brrr
	float randomColorR = static_cast<float>(((std::rand()) % 100) + 1) / 100.0f;
	float randomColorG = static_cast<float>(((std::rand()) % 100) + 1) / 100.0f;
	float randomColorB = static_cast<float>(((std::rand()) % 100) + 1) / 100.0f;
	
	_renderer->setClearColor(randomColorR, randomColorG, randomColorB, 1.0f);
	//----------------------------


	/* Loop until the user closes the window */
	while (!_window->shouldClose()) {
		_renderer->clearScreen();
		_renderer->drawTriangle();
		_renderer->swapBuffer();
		_input->pollEvents();
	}

	terminate();
}

void BaseGame::terminate() {
	glfwTerminate();
}

unsigned int BaseGame::createShader(const std::string& vertexShader, const std::string fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

unsigned int BaseGame::compileShader(const std::string& source, unsigned int type) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	//Hacer error handling. Try catches?

	return id;
}
