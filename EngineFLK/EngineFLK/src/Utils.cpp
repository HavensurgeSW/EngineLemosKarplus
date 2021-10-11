#include "Utils.h"

#include <iostream>

#define PI 3,14159265358979323846

float Utils::RandomRange(float min, float max)
{
	float valueToReturn;
	int minValue = static_cast<int>(min) * 100;
	int maxValue = static_cast<int>(max) * 100;

	int randomRange = RandomRange(minValue, maxValue);

	valueToReturn = static_cast<float>(randomRange) / 100.0f;

	return valueToReturn;
}

int Utils::RandomRange(int min, int max)
{
	return std::rand() % (max - min + 1) + min;
}


float Utils::RadiansToDegrees(float value) 
{
	return value * (180.0f / PI);
}

float Utils::DegreesToRadians(float value) 
{
	return value * (PI / 180.0f);
}
