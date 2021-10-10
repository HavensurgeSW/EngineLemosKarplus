#pragma once
#include "Exports.h"

#include <iostream>
#include <unordered_map> //a hash map/hash table (is it a dictionary?)

#include "Transform.h"
#include "Color.h"

struct FLK_API ShaderPaths 
{
	std::string vertexSource;
	std::string fragmentSource;
};

class FLK_API Shader
{
private:

	unsigned int rendererId;
	std::string filePath;
	std::unordered_map<std::string, int> cachedUniformLocations; //kinda cool

public:

	Shader();
	Shader(const std::string& filePath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetColorUniform(Color color); //will need to expand
	void SetTransformUniform(Transform transform);
	void CreateShader(const std::string& filePath);

private:

	int GetUniformLocation(const std::string& uniformName);
	unsigned int CreateShader(const std::string& vertexShader, const std::string fragmentShader);
	unsigned int CompileShader(const std::string& source, unsigned int type);
	ShaderPaths ParseShader(const std::string& filepath);
};

