#include "Animation.h"
#include <TimeManager.h>

Animation::Animation()
{
	uvs.SetValues(0.0f, 0.0f, 0.0f, 0.0f);
	dimensions.x = 0;
	dimensions.y = 0;
	currentFrame = 0;

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

void Animation::AddFrame(float durationInSeconds, int firstIndex, int lastIndex)
{
	length = durationInSeconds;
	this->firstIndex = firstIndex;
	this->lastIndex = lastIndex;
	currentFrame = firstIndex;
}

void Animation::UpdateFrame()
{
	time += TimeManager::GetDeltaTime();

	if (time >= length)
	{
		time -= length;
		currentFrame++;

		if (currentFrame > lastIndex)
		{
			currentFrame = firstIndex;
		}
	
		ChangeFrame();
		time = TimeManager::GetDeltaTime();
	}
}

void Animation::ChangeFrame()
{
	uvs = GetUVs(currentFrame);
}

Vector4 Animation::GetUVs(int index)
{
	// Might cause problems in the future, create Vector2Int struct?
	int xTile = index % static_cast<int>(dimensions.x);
	int yTile = index / static_cast<int>(dimensions.x);

	uvs.x = xTile / dimensions.x;
	uvs.y = yTile / dimensions.y;
	uvs.z = 1.0f  / dimensions.x;
	uvs.w = 1.0f  / dimensions.y;

	return uvs;
}

int Animation::GetCurrentFrame()
{
	return currentFrame;
}

Vector4 Animation::GetFrames()
{
	return GetUVs(GetCurrentFrame());
}



void Animation::SetName(std::string name)
{
	animationName = name;
}

std::string Animation::GetName() const
{
	return animationName;
}