#include "BaseGame.h"

#include "glfw3.h"

#include "utility/error_handling/ErrorHandling.h"
#include "utility/utils/Utils.h"
#include "utility/color/Color.h"

#include <time.h>
#include <fstream>
#include <sstream>
#include <string>

BaseGame::BaseGame() 
{
	window = new Window();
	renderer = new Renderer();
	input = new Input();
	collisionManager = new CollisionManager();
	entity = new Entity();
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
	srand(time(0));
	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
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
	renderer->GenerateBuffers();
	//InitErrorHandling();

	float arrnum = 8;
	float* arr = new float[arrnum];

	entity->SetPositions(arr);
	// int *arr = new int(n);

	ShaderPaths test = ParseShader("res/shaders/Basic.shader");
	unsigned int shader = CreateShader(test.vertexSource, test.fragmentSource);
	glUseProgram(shader);

	//----------------------------
	//haha pretty background colors go brrr
	renderer->SetClearColor(Color::RandomColor());
	//----------------------------

	/* Loop until the user closes the window */
	while (!window->ShouldClose()) 
	{
		renderer->ClearScreen();
		//renderer->DrawTriangle();
		renderer->DrawElement(6); //6 is the size of the indices array
		renderer->SwapBuffer();
		input->PollEvents();
	}	
	
	glDeleteProgram(shader); //should not be glDeleteShader() (Cherno How I Deal with Shaders in OpenGL 17:00)
	Terminate();
}

void BaseGame::Terminate() 
{
	glfwTerminate();
}

unsigned int BaseGame::CreateShader(const std::string& vertexShader, const std::string fragmentShader) 
{
	unsigned int program = glCreateProgram();
	unsigned int vShader = CompileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fShader = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vShader);
	glAttachShader(program, fShader);
	glLinkProgram(program);
	glValidateProgram(program);

	//glDetachShader(vs); //this method deletes the source code from the shader, kinda dangerous but techincally correct?
	//glDetachShader(fs);
	glDeleteShader(vShader);
	glDeleteShader(fShader);

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


ShaderPaths BaseGame::ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE,
		VERTEX,
		FRAGMENT
	};

	std::string line;
	ShaderType type = ShaderType::NONE;
	std::stringstream stringStreams[2];

	while (getline(stream, line))
	{
		if (line.find("#vertex_shader") != std::string::npos)
		{
			type = ShaderType::VERTEX;
		}
		else if (line.find("#fragment_shader") != std::string::npos)
		{
			type = ShaderType::FRAGMENT;
		}
		else
		{
			stringStreams[((int)type) - 1] << line << '\n';
		}
	}

	return { stringStreams[0].str(), stringStreams[1].str() };
}
