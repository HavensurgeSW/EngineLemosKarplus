#pragma once
#include "Texture.h"

#include <iostream>

class TextureImporter
{
private:
	friend class Texture;
public:
	TextureImporter();
	~TextureImporter();
	static Texture LoadTexture(const std::string& filePath);
};

