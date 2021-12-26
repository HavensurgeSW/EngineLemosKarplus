#ifndef SPRITE_H
#define SPRITE_H

#include "Entity2D.h"
#include "Texture.h"

class Vector4;

class FLK_API Sprite : public Entity2D
{
private:
	struct UV
	{
		float u;
		float v;
	};

protected:
	Texture texture;
	UV uvs[4];


public:
	Sprite();
	Sprite(Shader& shader, bool initalize = true);
	~Sprite();
	
	void Init();

	void SetTexture(const std::string& path);
	void SetTexture(const Texture& texture);
	void SetUVs(Vector4 uv);

	void UpdateTextureCoordinates();

	virtual void Draw();
};

#endif