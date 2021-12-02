#include "Animation.h"
#include <TimeManager.h>

Animation::Animation()
{
	dimensions.x = 0;
	dimensions.y = 0;
	currentFrameIndex = 0;

	firstIndex = 0;
	lastIndex = 0;
	time = 0;
}

Animation::~Animation()
{

}

void Animation::InitSpriteSheetDimensions(const Vector2& tileDimensions)
{
	dimensions = tileDimensions;
}

void Animation::AddFrame(float animationDuration, int firstIndex, int lastIndex)
{
	this->firstIndex = firstIndex;
	this->lastIndex = lastIndex;
	currentFrameIndex = firstIndex;

	for (int i = firstIndex; i < lastIndex; i++)
	{
		Frame frame;

		int xTile = i % static_cast<int>(dimensions.x);
		int yTile = i / static_cast<int>(dimensions.x);

		frame.uvs.x = xTile / dimensions.x;
		frame.uvs.y = yTile / dimensions.y;
		frame.uvs.z = 1.0f / dimensions.x;
		frame.uvs.w = 1.0f / dimensions.y;

		frames.push_back(frame);
	}

	frameDuration = animationDuration / frames.size();
}

void Animation::UpdateFrame()
{
	time += TimeManager::GetDeltaTime();

	if (time >= frameDuration)
	{
		time -= frameDuration;
		currentFrameIndex++;

		if (currentFrameIndex >= lastIndex)
		{
			currentFrameIndex = firstIndex;
		}
		
		SetCurrentFrame(currentFrameIndex);
		time = TimeManager::GetDeltaTime();
	}
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