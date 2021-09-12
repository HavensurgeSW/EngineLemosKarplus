#include "Utils.h"
#include <iostream>

float Utils::RandomRange(float min, float max)
{
	return min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

int Utils::RandomRange(int min, int max)
{
	return std::rand() % (max - min + 1) + min;
}

float Utils::GetRandomBetween0and1()
{
	return static_cast<float>((std::rand()) % 100) / 100.0f;
}
