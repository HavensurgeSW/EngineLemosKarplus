#include "Utils.h"

#include <iostream>

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