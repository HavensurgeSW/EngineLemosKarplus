#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
	hasAnimations = false;
}

AnimatedSprite::AnimatedSprite(Shader& shader, Vector2 spriteSheetDimensions, bool initalize) : Sprite(shader, initalize)
{
	this->spriteSheetDimensions = spriteSheetDimensions;
	hasAnimations = false;
}

AnimatedSprite::AnimatedSprite(Shader& shader, int framesPerRow, int framesPerCollumn, bool initalize)
{
	spriteSheetDimensions = { static_cast<float>(framesPerRow), static_cast<float>(framesPerCollumn) };
	hasAnimations = false;
}

AnimatedSprite::~AnimatedSprite()
{

}

void AnimatedSprite::AddAnimation(AnimationData animationData)
{
	AddAnimation(animationData.animationName, 
				 animationData.animationDuration,
				 animationData.startingFrame, animationData.finalFrame,
			     animationData.loop);
}

void AnimatedSprite::AddAnimation(std::string animationName, float animationDuration, int startingFrame, int finalFrame, bool loop)
{
	if (animations.find(animationName) != animations.end())
	{
		std::cout << "Animation with the name '" << animationName << "' has already been added." << std::endl;
		return;
	}
	
	Animation animation;
	animation.SetName(animationName);
	animation.SetSpriteSheetDimensions(spriteSheetDimensions);
	animation.AddFrames(animationDuration, startingFrame, finalFrame);
	animation.SetLoopStatus(loop);
	animations[animation.GetName()] = animation;

	hasAnimations = !animations.empty();
}

void AnimatedSprite::RestartAnimation()
{
	currentAnimation.Reset();
}

void AnimatedSprite::StopAnimation()
{
	currentAnimation.Stop();
}

void AnimatedSprite::SetCurrentAnimation(std::string animationName)
{
	if (animations.find(animationName) == animations.end())
	{
		std::cout << "Animation with the name '" << animationName << "' doesnt exist" << std::endl;
		return;
	}

	currentAnimation = animations[animationName];
}

void AnimatedSprite::DrawAnimation()
{
	const Vector4& uv = currentAnimation.GetFrameUVs();

	uvs[0].u = uv.x + uv.z;
	uvs[0].v = uv.y + uv.w;

	uvs[1].u = uv.x + uv.z;
	uvs[1].v = uv.y;

	uvs[2].u = uv.x;
	uvs[2].v = uv.y;

	uvs[3].u = uv.x;
	uvs[3].v = uv.y + uv.w;

	SetTextureCoordinates({ uvs[0].u, uvs[0].v },
						  { uvs[1].u, uvs[1].v },
						  { uvs[2].u, uvs[2].v },
						  { uvs[3].u, uvs[3].v });


	vertexBuffer.SetData(quadVertices, quadVerticesAmount);
	vertexArray.SetData(vertexBuffer);
	currentAnimation.UpdateAnimation();
}

void AnimatedSprite::Draw()
{
	if (hasAnimations)
	{
		DrawAnimation();
	}

	Sprite::Draw();
}