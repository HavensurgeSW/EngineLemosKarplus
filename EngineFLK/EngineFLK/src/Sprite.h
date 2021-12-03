#ifndef SPRITE_H
#define SPRITE_H

#include "Exports.h"

#include "Entity2D.h"
#include "Texture.h"

class FLK_API Sprite : public Entity2D
{
protected:
	Texture texture;

	float spriteVertices[16] =
	{	 //position      //texture coords
		 0.5f,  0.5f,       1.0f, 1.0f,
		 0.5f, -0.5f,       1.0f, 0.0f,
		-0.5f, -0.5f,       0.0f, 0.0f,
		-0.5f,  0.5f,       0.0f, 1.0f
	};
	unsigned int spriteIndices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

public:
	Sprite();
	Sprite(Renderer* renderer, Shader& shader, bool initalize = true);
	~Sprite();
	
	void Init();

	void SetColor(Color color);
	void SetTexture(const std::string& path);

	virtual void Draw();
};

#endif