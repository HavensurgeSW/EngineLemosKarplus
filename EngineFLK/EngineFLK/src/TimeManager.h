#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include "Exports.h"

#include <chrono>

class FLK_API TimeManager
{
private:
	float fpsElapsedTime;
	int frames;

	std::chrono::system_clock::time_point currentTime;
	std::chrono::system_clock::time_point previousTime;

	static float fps;
	static std::chrono::duration<float> deltaTime;

public:
	TimeManager();
	~TimeManager();

	void UpdateTime();
	void UpdateFPS();
	
	static const float GetFPS();
	static const float GetDeltaTime();
};


#endif