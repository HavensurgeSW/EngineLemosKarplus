#include "Texture.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

Texture::Texture()
{
}

Texture::Texture(const std::string& path, const bool isTransparent) : textureID(0), filePath(path), data(nullptr), width(0), height(0), bytesPerPixel(0)
{
	stbi_set_flip_vertically_on_load(false);
	
	data = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 0);
	
	if (!data)
	{
		std::cout << "Failed to load texture." << std::endl;
		return;
	}
	
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	if (bytesPerPixel == 4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	stbi_image_free(data);


	//glGenTextures(1, &textureID);
	//glBindTexture(GL_TEXTURE_2D, textureID);
	//
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//
	//stbi_set_flip_vertically_on_load(true);
	//
	//GLenum format = GL_RED;
	//switch (bytesPerPixel)
	//{
	//case 1:
	//	format = GL_RED;
	//case 3:
	//	format = GL_RGB;
	//case 4:
	//	format = GL_RGBA;
	//}
	//
	//localBuffer = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 0);
	//
	//if (localBuffer) {
	//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	//
	//	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, localBuffer);
	//
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	//else {
	//	std::cout << "Failed to load texture" << " - " << stbi_failure_reason() << std::endl;
	//}
	//stbi_image_free(localBuffer);
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::LoadTexture(const std::string& path)
{
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	stbi_set_flip_vertically_on_load(true);
	
	GLenum internalformat = GL_RGB;
	GLenum format = GL_RGB;
	switch (bytesPerPixel)
	{
	case 1:
		internalformat = GL_RED;
		format = GL_RED;
	case 3:
		internalformat = GL_RGB;
		format = GL_RGB;
	case 4:
		internalformat = GL_RGBA8;
		format = GL_RGBA;
	}
	
	data = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 0);
	
	if (data) {
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
		glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture" << " - " << stbi_failure_reason() << std::endl;
	}
	stbi_image_free(data);
}

int Texture::GetWidth() const
{
	return width;
}

int Texture::GetHeight() const
{
	return height;
}

int Texture::GetId() const
{
	return textureID;
}
