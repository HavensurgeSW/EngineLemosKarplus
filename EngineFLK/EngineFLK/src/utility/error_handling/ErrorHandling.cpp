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