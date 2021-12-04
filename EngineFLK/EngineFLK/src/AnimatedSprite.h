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

	std::map<std::string, Animation> animations;

	Animation currentAnimation;

	UV uvs[4];
	bool hasAnimations;

public:

	AnimatedSprite();
	AnimatedSprite(Renderer* renderer, Shader& shader, bool initalize = true);
	~AnimatedSprite();

	void AddAnimation(AnimationData animationData);
	void AddAnimation(std::string animationName, float animationDuration, int framesPerRow, int framesPerCollumn, int startingFrame, int finalFrame, bool loop);
	
	void SetCurrentAnimation(std::string animationName);
	void RestartAnimation();
	void StopAnimation();

	void Draw() override;

private:
	void DrawAnimation();
};

#endif