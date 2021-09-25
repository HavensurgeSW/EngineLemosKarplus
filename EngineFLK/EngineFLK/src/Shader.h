#pragma once
#include <iostream>
#include <unordered_map> //a hash map/hash table (is it a dictionary?)
#include "Exports.h"

#include "Color.h"

struct FLK_API ShaderPaths {
	std::string vertexSource;
	std::string fragmentSource;
};

class FLK_API Shader
{
private:

	unsigned int rendererId;
	std::string filePath;
	std::unordered_map<std::string, int> uniformLocationsSaved; //kinda cool

public:

	Shader();
	Shader(const std::string& filePath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetColorUniform(const std::string uniformName, Color color); //will need to expand

private:

	int GetUniformLocation(const std::string& uniformName);
	unsigned int CreateShader(const std::string& vertexShader, const std::string fragmentShader);
	unsigned int CompileShader(const std::string& source, unsigned int type);
	ShaderPaths ParseShader(const std::string& filepath);
};

