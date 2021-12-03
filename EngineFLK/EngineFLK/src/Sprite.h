#ifndef SPRITE_H
#define SPRITE_H

#include "Exports.h"

#include "Entity2D.h"
#include "Animation.h"
#include "Texture.h"

struct FLK_API UV
{
	float u;
	float v;
};

class FLK_API Sprite : public Entity2D
{
private:
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

	Animation* animation;
	UV uvs[4];

	bool hasAnimation;

public:
	Sprite();
	Sprite(Renderer* renderer, Shader& shader, bool initalize = true);
	Sprite(Renderer* renderer, Shader& shader, bool initalize, bool useAnimation);
	~Sprite();
	
	void Init();

	void SetRenderer(Renderer* renderer);
	void SetShader(Shader& shader);
	void SetColor(Color color);
	void SetTexture(const std::string& path);

	void SetAnimationData(int framePerRow, int framePerCollumn, float animationDuration, int firstIndex, int lastIndex);
	void DrawAnimation(Vector4 uvRect);

	void AddAnimation(std::string animationName);
	Animation* GetAnimation() const;

	void Draw();
};

#endif