#include "Animation.h"
#include <TimeManager.h>

Animation::Animation()
{
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

void Animation::AddFrame(float durationInSec, int firstIndex, int lastIndex)
{
	length = durationInSec;
	firstIndex = firstIndex;
	lastIndex = lastIndex;
	currentFrame = firstIndex;

	for (int i = firstIndex; i <= lastIndex; i++)
	{
		Frame frame;
		int xTile = i % dimensions.x;
		int yTile = i / dimensions.x;

		frame.uv.x = xTile / (float)dimensions.x;
		frame.uv.y = yTile / (float)dimensions.y;
		frame.uv.z = 1.0f / (float) dimensions.x;
		frame.uv.w = 1.0f / (float) dimensions.y;

		frame.framesCount = i;
		frames.push_back(frame);
	}
}

void Animation::UpdateFrame(float deltaTime)
{
	time += deltaTime;// TimeManager::GetDeltaTime();
	//std::cout << time << std::endl;
	if (time >= length)
	{
		time -= length;
	
		currentFrame++;
		if (currentFrame > lastIndex)
			currentFrame = firstIndex;
	
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

int Animation::GetCurrentFrame() const
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