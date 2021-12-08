#ifndef SPRITE_H
#define SPRITE_H

#include "Entity2D.h"
#include "Texture.h"

class FLK_API Sprite : public Entity2D
{
protected:
	Texture texture;

public:
	Sprite();
	Sprite(Shader& shader, bool initalize = true);
	~Sprite();
	
	void Init();

	void SetTexture(const std::string& path);
	void SetTexture(const Texture& texture);


	void SetTextureCoordinates(Vector2 topRight, Vector2 bottomRight, Vector2 bottomLeft, Vector2 topLeft);

	virtual void Draw();
};

#endif