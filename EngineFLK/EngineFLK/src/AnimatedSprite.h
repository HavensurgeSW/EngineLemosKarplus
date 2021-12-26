#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "Sprite.h"
#include "Animation.h"

#include <map>

class FLK_API AnimatedSprite : public Sprite
{
private:

	std::map<std::string, Animation> animations;

	Animation currentAnimation;

	Vector2 spriteSheetDimensions;

	bool hasAnimations;

public:

	AnimatedSprite();
	AnimatedSprite(Shader& shader, Vector2 spriteSheetDimensions, bool initalize = true);
	AnimatedSprite(Shader& shader, int framesPerRow, int framesPerCollumn, bool initalize = true);
	~AnimatedSprite();

	void AddAnimation(AnimationData animationData);
	void AddAnimation(std::string animationName, float animationDuration, int startingFrame, int finalFrame, bool loop);
	
	void SetCurrentAnimation(std::string animationName);
	void RestartAnimation();
	void StopAnimation();

	void Draw() override;

private:
	void UpdateAnimation();
};

#endif