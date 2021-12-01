#include "Animation.h"
#include <TimeManager.h>

Animation::Animation()
{
	uvs = vec4(0, 0, 0, 0);
	dimensions.x = 0;
	dimensions.y = 0;
	currentFrame = 0;

	firstIndex = 0;
	lastIndex = 0;
}

Animation::~Animation()
{

}

void Animation::InitSpriteSheetDimensions(const glm::ivec2& tileDimensions)
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
	//std::cout << time << std::endl;
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

vec4 Animation::GetUVs(int index)
{
	int xTile = index % dimensions.x;
	int yTile = index / dimensions.x;

	uvs.x = xTile / (float)dimensions.x;
	uvs.y = yTile / (float)dimensions.y;
	uvs.z = 1.0f / (float) dimensions.x;
	uvs.w = 1.0f / (float) dimensions.y;

	return uvs;
}

int Animation::GetCurrentFrame()
{
	return currentFrame;
}



void Animation::SetName(std::string name)
{
	animationName = name;
}

std::string Animation::GetName() const
{
	return animationName;
}