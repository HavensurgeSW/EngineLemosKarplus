#include "BaseGame.h"

#include "glfw3.h"

#include <time.h>

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

void BaseGame::LaunchGod() 
{
	srand(time(NULL));

	/* Initialize the library */
	if (!glfwInit()) 
	{
		std::cout << "Error de inicializacion" << std::endl;
	}

	window->SetWindow(window->CreateWindow(800, 600, "Hello World", NULL, NULL));

	if (!window->GetWindow()) {

		std::cout << "Error. Window is null, terminating." << std::endl;
		Terminate();
	}

	renderer->SetWindow(window);

	/* Make the window's context current */
	renderer->MakeContextCurrent(window);
	renderer->InitGlew();
	renderer->GenBuffers();

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

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	//----------------------------
	//haha pretty background colors go brrr
	float randomColorR = static_cast<float>(((std::rand()) % 100) + 1) / 100.0f;
	float randomColorG = static_cast<float>(((std::rand()) % 100) + 1) / 100.0f;
	float randomColorB = static_cast<float>(((std::rand()) % 100) + 1) / 100.0f;
	
	renderer->SetClearColor(randomColorR, randomColorG, randomColorB, 1.0f);
	//----------------------------


	/* Loop until the user closes the window */
	while (!window->ShouldClose()) 
	{
		renderer->ClearScreen();
		renderer->DrawTriangle();
		renderer->SwapBuffer();
		input->PollEvents();
	}

	Terminate();
}

void BaseGame::Terminate() 
{
	glfwTerminate();
}

unsigned int BaseGame::CreateShader(const std::string& vertexShader, const std::string fragmentShader) 
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fs = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

unsigned int BaseGame::CompileShader(const std::string& source, unsigned int type)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) 
	{
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
