#ifndef TEXTURE_H
#define TEXTURE_H

#include "Exports.h"

#include <string>

#include "LibIncludes.h"

class FLK_API Texture
{
private:
	
	unsigned int textureID;
	std::string filePath;
	unsigned char* localBuffer;

	int width;
	int height;
	
	int bytesPerPixel;

public:
	Texture();
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;
	void LoadTexture(const std::string& path);

	/*inline*/ int GetWidth() const;
	/*inline*/ int GetHeight() const;
};

#endif