#pragma once
#include "glew.h"
#include "glfw3.h"

#include <iostream>

//These are macros
#define ASSERT(x) if(!(x)) __debugbreak();
//ASSERT is a built-in macro that just validates a condition (in this case, the condition is "x")
//In short, if x is false, it calls __debugbreak(), which puts a Debug Break Point where the condition failed


//EXTREMELY FRAGILE, adding a simple space after the ending \ could unironically break the #define
#define GLCheck(x)\
	GLClearError();\
	x;\
	ASSERT(GLCheckError(__FILE__, #x, __LINE__))

//This one's kinda quirky and haha funny
//This #define GLCheck(x) is the real error handler
//It takes an x input (a function) and does the following 3 things:
//This define kinda works like a main()

//1) It calls GLClearError() to clear any previous errors
//2) It calls "x", which is the function, meaning you are just calling the function
//3) Calls the previous #define called ASSERT to check for errors in the previous x function

//To use GLCheck, you just need to wrap whatever GL function with GLCall and boom, error handling
//Would it be smart to encapsulate every single GL function in this?

void InitErrorHandling();
void GLClearError();
bool GLCheckError(const char* sourceFile, const char* functionName, int errorLine);
static void GLAPIENTRY GLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParameters);