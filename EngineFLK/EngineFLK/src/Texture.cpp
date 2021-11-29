#include "Texture.h"

#include "ErrorHandling.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

Texture::Texture()
{
	textureID = 0;
	filePath = "";
	localBuffer = nullptr;
	width = 0;
	height = 0;
	amountOfChannels = 0;
}

Texture::Texture(const std::string& path) : textureID(0), filePath(path), localBuffer(nullptr), width(0), height(0), amountOfChannels(0)
{
	stbi_set_flip_vertically_on_load(false);

	localBuffer = stbi_load(path.c_str(), &width, &height, &amountOfChannels, 0);

	if (!localBuffer)
	{
		std::cout << "Failed to load texture." << std::endl;
		return;
	}

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (amountOfChannels == 4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, localBuffer);
	}

	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(localBuffer);
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
	GLCheck(glGenTextures(1, &textureID));
	GLCheck(glBindTexture(GL_TEXTURE_2D, textureID));

	GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

	stbi_set_flip_vertically_on_load(true);

	localBuffer = stbi_load(path.c_str(), &width, &height, &amountOfChannels, 0);

	if (!localBuffer)
	{
		std::cout << "Failed to load texture." << std::endl;
		return;
	}

	GLCheck(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

	GLint internalFormat = GL_RGB;
	GLint format = GL_RGB;

	switch (amountOfChannels)
	{
	case 3:
		internalFormat = GL_RGBA;
		format = GL_RGB;
		break;

	case 4:
		internalFormat = GL_RGBA;
		format = GL_RGBA;
		break;
	}

	GLCheck(glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, localBuffer));

	GLCheck(glGenerateMipmap(GL_TEXTURE_2D));
	GLCheck(glBindTexture(GL_TEXTURE_2D, 0));

	if (localBuffer) 
	{
		stbi_image_free(localBuffer);
	}
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
