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
	glDeleteProgram(rendererId); //should not be glDeleteShader() (Cherno How I Deal with Shaders in OpenGL 17:00)
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

void Shader::SetTransformUniform(glm::mat4 trans)
{
	glUniformMatrix4fv(GetUniformLocation("u_Transform"), 1, GL_FALSE, glm::value_ptr(trans));
}

void Shader::CreateShader(const std::string& filePath)
{
	ShaderPaths shaderPaths = ParseShader(filePath);
	rendererId = CreateShader(shaderPaths.vertexSource, shaderPaths.fragmentSource);
}


int Shader::GetUniformLocation(const std::string& uniformName)
{
	if (uniformLocationsSaved.find(uniformName) != uniformLocationsSaved.end())
	{
		return uniformLocationsSaved[uniformName];
	}

	int location = glGetUniformLocation(rendererId, uniformName.c_str()); //searches for the "uniform" or "rendererId" value inside the .shader file
	
	if (location == -1)
	{
		std::cout << "Shader.cpp error" << std::endl << "Uniform " << uniformName << " doesnt exist." << std::endl;
	}

	uniformLocationsSaved[uniformName] = location;
	return location;
}

unsigned int Shader::CompileShader(const std::string& source, unsigned int type)
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

	return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vShader = CompileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fShader = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vShader);
	glAttachShader(program, fShader);
	glLinkProgram(program);
	glValidateProgram(program);

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