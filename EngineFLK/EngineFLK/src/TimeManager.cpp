#include "TimeManager.h"

float TimeManager::fps = 0.0f;
std::chrono::duration<float> TimeManager::deltaTime = std::chrono::duration<float>(0.0f);

TimeManager::TimeManager()
{
	fpsElapsedTime = 0.0f;
	frames = 0;

	previousTime = std::chrono::system_clock::now();
}

TimeManager::~TimeManager()
{
}


void TimeManager::UpdateTime()
{
	currentTime = std::chrono::system_clock::now();
	deltaTime = currentTime - previousTime;
	previousTime = std::chrono::system_clock::now();
}

void TimeManager::UpdateFPS()
{
	fps = 1.0f / deltaTime.count();
}


const float TimeManager::GetFPS()
{
	return fps;
}

const float TimeManager::GetDeltaTime()
{
	return deltaTime.count();
}