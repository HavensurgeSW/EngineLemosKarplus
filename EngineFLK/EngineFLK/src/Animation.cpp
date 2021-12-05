#include "Animation.h"
#include <TimeManager.h>

Animation::Animation()
{
	dimensions.x = 0;
	dimensions.y = 0;
	currentFrameIndex = 0;

	startingFrame = 0;
	finalFrame = 0;
	timer = 0;
	maxFrames = 0;
}

Animation::~Animation()
{

}

void Animation::SetSpriteSheetDimensions(const Vector2& tileDimensions)
{
	dimensions = tileDimensions;
}

void Animation::AddFrames(float animationDuration, int startingFrame, int finalFrame)
{
	this->startingFrame = startingFrame;
	this->finalFrame = finalFrame;
	currentFrameIndex = 0;
	maxFrames = finalFrame - startingFrame;

	for (int i = startingFrame; i < finalFrame; i++)
	{
		Frame frame;

		int xTile = i % static_cast<int>(dimensions.x);
		int yTile = i / static_cast<int>(dimensions.x);

		frame.uvs.x = xTile / dimensions.x;
		frame.uvs.y = yTile / dimensions.y;
		frame.uvs.z = 1.0f / dimensions.x;
		frame.uvs.w = 1.0f / dimensions.y;

		frames.push_back(frame);
		//maxFrames++;
	}

	frameDuration = animationDuration / frames.size();
}

void Animation::SetLoopStatus(bool loop)
{
	this->loop = loop;
}

void Animation::UpdateAnimation()
{
	if (stop)
	{
		return;
	}

	timer += TimeManager::GetDeltaTime();

	if (timer >= frameDuration)
	{
		timer -= frameDuration;
		currentFrameIndex++;

		if (currentFrameIndex >= maxFrames)
		{
			if(!loop)
			{
				stop = true;
				return;
			}

			currentFrameIndex = 0;
		}
		
		SetCurrentFrame(currentFrameIndex);
		timer = TimeManager::GetDeltaTime();
	}
}

void Animation::Reset()
{
	currentFrameIndex = 0;
	timer = frameDuration;
	stop = false;
}

void Animation::Stop()
{
	stop = true;
}

Vector4 Animation::GetFrames() const
{
	return currentFrame.uvs;
}

void Animation::SetCurrentFrame(int index)
{
	currentFrame = frames[index];
}


void Animation::SetName(std::string name)
{
	animationName = name;
}

std::string Animation::GetName() const
{
	return animationName;
}