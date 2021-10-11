#pragma once
#include "Exports.h"

struct FLK_API Utils
{
	static float RandomRange(float min, float max);
	static int RandomRange(int min, int max);

	static float DegreesToRadians(float value);
	static float RadiansToDegrees(float value);
};