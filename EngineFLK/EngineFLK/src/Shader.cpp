#include "Shader.h"

#include "glew.h"

#include <fstream>
#include <sstream>


Shader::Shader()
{

}

Shader::Shader(const std::string& filePath) : filePath(filePath)
{
	ShaderPaths shaderPaths = ParseShader(filePath);
	rendererId = CreateShader(shaderPaths.vertexSource, shaderPaths.fragmentSource);
}

Shader::~Shader()
{
	glDeleteProgram(rendererId); //similar to delete shader, (did this one delete the source code for the shader?)
	                             //Code reminder: in this case, it should not be glDeleteShader() (Cherno "How I Deal with Shaders in OpenGL" 17:00)
}

void Shader::Bind() const
{
	glUseProgram(rendererId);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}

void Shader::SetColorUniform(Color color)
{
	glUniform4f(GetUniformLocation("u_Color"), color.r, color.g, color.b, color.a); //finds the "location" index and sets the vec4 Color
}

void Shader::SetTransformUniform(Transform transform)
{
	glUniformMatrix4fv(GetUniformLocation("u_Transform"), 1, GL_FALSE, glm::value_ptr(transform.GetTransform()));
}

void Shader::CreateShader(const std::string& filePath)
{
	ShaderPaths shaderPaths = ParseShader(filePath);
	rendererId = CreateShader(shaderPaths.vertexSource, shaderPaths.fragmentSource);
}


int Shader::GetUniformLocation(const std::string& uniformName)
{
	if (cachedUniformLocations.find(uniformName) != cachedUniformLocations.end())
	{
		return cachedUniformLocations[uniformName];
	}

	int location = glGetUniformLocation(rendererId, uniformName.c_str()); //glGetUniformLocation searches for the id/location of the "uniform" (shader variable) inside the .shader file
	
	if (location == -1)
	{
		std::cout << "Shader unifrom " << uniformName << " not located or doesnt exist." << std::endl;
	}

	cachedUniformLocations[uniformName] = location;
	return location;
}

unsigned int Shader::CompileShader(const std::string& source, unsigned int type)
{
	unsigned int id = glCreateShader(type); //creates a shader object and returns the shader Id, which is used to reference the shader throughout the engine.
	                                        //the shader type must be specified (vertex or fragment)
	const char* src = source.c_str();

	glShaderSource(id, 1, &src, nullptr);   //obtains the location of the source code of the shader and gets stored in the previously created "id" variable
	
	glCompileShader(id);  //compiles the source code of the shader. Returns a GL_FALSE or GL_TRUE depending if it compiled correctly or not, and that value is stored inside the shader itself

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result); //returns a specific parameter of a shader (in this case, the result of the previousCompileShader)

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message); //returns a information log for the specified shader. This log is modified when

		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
		std::cout << message << std::endl;

		glDeleteShader(id); //frees memory and unlinks the id with the shader program, making it useless. Just deletes the shader bruh.

		return 0;
	}

	return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vShader = CompileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fShader = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vShader); //links a shader object to a program object
	glAttachShader(program, fShader);
	glLinkProgram(program); //links the vertex and fragment shader
	glValidateProgram(program); //makes sure that the contents in program can actually be executed, depending on the state of OpenGL. This information is stored in program

	//glDetachShader(vShader); //this method deletes the source code from the shader, kinda dangerous but techincally correct?
	//glDetachShader(fShader);
	glDeleteShader(vShader);
	glDeleteShader(fShader);

	return program;
}

ShaderPaths Shader::ParseShader(const std::string& filepath)
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