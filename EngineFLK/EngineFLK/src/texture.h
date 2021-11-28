#ifndef TEXTURE_H
#define TEXTURE_H

#include "Exports.h"

#include <string>

#include "LibIncludes.h"

class FLK_API Texture
{
private:
	
	unsigned int textureID;
	unsigned char* data;
	std::string filePath;

	int width;
	int height;
	
	int bytesPerPixel;

public:
	Texture();
	Texture(const std::string& path, const bool isTransparent = true);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;
	void LoadTexture(const std::string& path);

	/*inline*/ int GetWidth() const;
	/*inline*/ int GetHeight() const;
	/*inline*/ int GetId() const;
};

#endif