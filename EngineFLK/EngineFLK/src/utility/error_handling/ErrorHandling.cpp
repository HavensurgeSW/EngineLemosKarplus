#include "ErrorHandling.h"

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR); //Clears all errors
}

bool GLCheckError(const char* sourceFile, const char* functionName, int errorLine)
{
	while (GLenum error = glGetError()) //loops as long as "error" is not 0 (while there are errors)
	{
		std::cout << "[OpenGL Error]: Error Flag (" << error << ")" << std::endl;
		std::cout << "File: '" << sourceFile << "'" << std::endl;
		std::cout << "Function: " << functionName << std::endl;
		std::cout << "Line " << errorLine << std::endl;
		return false; //breaks the loop on found error, kinda breaks the point of the loop but its needed
	}

	return true;
}

void GLAPIENTRY GLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParameters)
{
	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:
		std::cout << "Error Flag: " << id << std::endl;
		std::cout << "Error: " << message << std::endl;
		std::cout << "Severity: HIGH" << std::endl;
		break;

	case GL_DEBUG_SEVERITY_MEDIUM:
		std::cout << "Error Flag: " << id << std::endl;
		std::cout << "Error: " << message << std::endl;
		std::cout << "Severity: MEDIUM" << std::endl;
		break;

	case GL_DEBUG_SEVERITY_LOW:
		std::cout << "Severity: LOW" << std::endl;
		std::cout << "Error Flag: " << id << std::endl;
		std::cout << "Error: " << message << std::endl;
		break;
	}	
}

void InitErrorHandling()
{
	glDebugMessageCallback(GLLogMessage, nullptr);
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
}
