#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "Sprite.h"
#include "Animation.h"

#include <map>

class FLK_API AnimatedSprite : public Sprite
{
private:
	struct UV
	{
		float u;
		float v;
	};

	std::map<std::string, Animation> animations; //might need to make it an Animation*

	Animation* animation;
	UV uvs[4];
	bool hasAnimation;

public:

	AnimatedSprite();
	AnimatedSprite(Renderer* renderer, Shader& shader, bool initalize = true);
	~AnimatedSprite();

	void SetAnimationData(int framePerRow, int framePerCollumn, float animationDuration, int firstIndex, int lastIndex);
	void DrawAnimation(Vector4 uvRect);

	void AddAnimation(std::string animationName);
	Animation GetAnimation(std::string animationName);

	void Draw() override;
};

#endif
