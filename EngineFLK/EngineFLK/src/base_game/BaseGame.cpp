#include "BaseGame.h"

#include "glfw3.h"

#include "utility/error_handling/ErrorHandling.h"
#include "utility/utils/Utils.h"
#include "utility/color/Color.h"
#include "shader/Shader.h"

#include <time.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vertex_buffer/VertexBuffer.h>
#include <index_buffer/IndexBuffer.h>

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

	renderer->MakeContextCurrent(window);
	renderer->InitGlew();

	//renderer->GenerateBuffers();
	const int maxPositions = 8;

	float positions[maxPositions] = //Vertices
	{
		-0.5f, -0.5f, //vertex 0
		 0.5f, -0.5f, //vertex 1
		 0.5f,  0.5f, //vertex 2
		-0.5f,  0.5f  //vertex 3 for square
	};

	const int maxIndices = 6;
	unsigned int indices[maxIndices] = //Triangle connections
	{
		0, 1, 2, //triangle 1
		2, 3, 0  //triangle 2 
	};

	//Color shaderColor = Color::RandomColor();
    //shader.SetColorUniform("u_Color", shaderColor);
	Shader shader("res/shaders/Basic.shader");

	VertexBuffer vertexBuffer(positions, maxPositions * sizeof(float));

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //float * 2 implica que cada seccion de memoria del vertice tiene el tamaño de 2 floats. X e Y
	
    // ^
	// |
	// where tf do i move these

	IndexBuffer indexBuffer(indices, maxIndices);

	//renderer->Unbind(); ????
	renderer->SetClearColor(Color::RandomColor());

	while (!window->ShouldClose())
	{
		renderer->ClearScreen();

		renderer->TestDraw(vertexBuffer, indexBuffer, shader);
		renderer->SwapBuffer();
		input->PollEvents();
	}

	Terminate();
}

void BaseGame::Terminate()
{
	glfwTerminate();
}