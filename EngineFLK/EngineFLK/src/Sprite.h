#ifndef SPRITE_H
#define SPRITE_H

#include "Exports.h"

#include "Entity2D.h"
#include "Texture.h"

class FLK_API Sprite : public Entity2D
{
protected:
	Texture texture;

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