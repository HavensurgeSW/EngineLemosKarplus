#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
	animation = NULL;
	hasAnimation = false;
}

AnimatedSprite::AnimatedSprite(Renderer* renderer, Shader& shader, bool initalize) : Sprite(renderer, shader, initalize)
{
	animation = new Animation();
	hasAnimation = true;
}

AnimatedSprite::~AnimatedSprite()
{
	if (animation != NULL)
	{
		delete animation;
	}
}


void AnimatedSprite::AddAnimation(std::string animationName)
{
	if (animations.find(animationName) != animations.end())
	{
		std::cout << "Animation with the name '" << animationName << "' has already been added" << std::endl;
		return;
	}
	
	Animation animation;
	animation.SetName(animationName);
	animations[animation.GetName()] = animation;
}

Animation AnimatedSprite::GetAnimation(std::string animationName)
{
	return animations[animationName];
}

void AnimatedSprite::DrawAnimation(Vector4 uvRect)
{
	//Set UV
	uvs[0].u = uvRect.x + uvRect.z;
	uvs[0].v = uvRect.y + uvRect.w;

	uvs[1].u = uvRect.x + uvRect.z;
	uvs[1].v = uvRect.y;

	uvs[2].u = uvRect.x;
	uvs[2].v = uvRect.y;

	uvs[3].u = uvRect.x;
	uvs[3].v = uvRect.y + uvRect.w;


	quadVertices[6] = uvs[0].u;
	quadVertices[7] = uvs[0].v;

	quadVertices[14] = uvs[1].u;
	quadVertices[15] = uvs[1].v;

	quadVertices[22] = uvs[2].u;
	quadVertices[23] = uvs[2].v;

	quadVertices[30] = uvs[3].u;
	quadVertices[31] = uvs[3].v;
}

void AnimatedSprite::Draw()
{
	if (hasAnimation)
	{
		DrawAnimation(animation->GetFrames());
		vertexBuffer.SetData(quadVertices, quadVerticesAmount);
		vertexArray.SetData(vertexBuffer);
		animation->UpdateFrame();
	}

	Sprite::Draw();
}

void AnimatedSprite::SetAnimationData(int framePerRow, int framePerCollumn, float animationDuration, int firstIndex, int lastIndex)
{
	if (animation != NULL)
	{
		animation->InitSpriteSheetDimensions({ static_cast<float>(framePerRow), static_cast<float>(framePerCollumn) });
		animation->AddFrame(animationDuration, firstIndex, lastIndex);
	}
}
