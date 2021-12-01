#include "Animation.h"

Animation::Animation()
{
	frameCount = 0;
}

Animation::~Animation()
{

}

void Animation::SetName(std::string name)
{
	animationName = name;
}

std::string Animation::GetName() const
{
	return animationName;
}