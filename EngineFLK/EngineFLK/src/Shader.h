#ifndef SHADER_H
#define SHADER_H
#include "Exports.h"

#include <iostream>
#include <unordered_map> //a hash map/hash table (is it a dictionary?)

class Transform;
struct Color;

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
	void Delete() const;

	void SetColorUniform(const Color color);
	void SetTransformUniform(const Transform transform);
	void SetTextureUniform(const int slot);
	void CreateShader(const std::string& filePath);

	void EnableAttributePointer(/*fill with parameters*/);

private:

	int GetUniformLocation(const std::string& uniformName);
	unsigned int CreateShader(const std::string& vertexShader, const std::string fragmentShader);
	unsigned int CompileShader(const std::string& source, unsigned int type); //could be transformed into nested function within CreateShader()
	ShaderPaths ParseShader(const std::string& filepath);
};

#endif