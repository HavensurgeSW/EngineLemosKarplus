#include "Color.h"

#include "utility/utils/Utils.h"

#include <iostream>

Color::Color()
{
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
	a = 1.0f;
}

Color::Color(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	a = 1.0f;
}

Color::Color(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color Color::Red()
{
	return Color(1.0f, 0.0f, 0.0f, 1.0f);
}

Color Color::Green()
{
	return Color(0.0f, 1.0f, 0.0f, 1.0f);
}

Color Color::Blue()
{
	return Color(0.0f, 0.0f, 1.0f, 1.0f);
}

Color Color::Yellow()
{
	return Color(1.0f, 1.0f, 0.0f, 1.0f);
}

Color Color::Black()
{
	return Color(0.0f, 0.0f, 0.0f, 1.0f);
}

Color Color::White()
{
	return Color(1.0f, 1.0f, 1.0f, 1.0f);
}

Color Color::Purple()
{
	return Color(0.4f, 0.0f, 0.4f, 1.0f);
}

Color Color::Clear()
{
	return Color(1.0f, 1.0f, 1.0f, 0.0f);
}


Color Color::RandomRedShade()
{
	float randomRed = Utils::RandomRange(0.0f, 1.0f);
	return Color(randomRed, 0.0f, 0.0f, 1.0f);
}

Color Color::RandomGreenShade()
{
	float randomGreen = Utils::RandomRange(0.0f, 1.0f);
	return Color(0.0f, randomGreen, 0.0f, 1.0f);
}

Color Color::RandomBlueShade()
{
	float randomBlue = Utils::RandomRange(0.0f, 1.0f);
	return Color(0.0f, 0.0f, randomBlue, 1.0f);
}

Color Color::RandomColor()
{
	float randomRed = Utils::RandomRange(0.0f, 1.0f);
	float randomGreen = Utils::RandomRange(0.0f, 1.0f);
	float randomBlue = Utils::RandomRange(0.0f, 1.0f);

	return Color(randomRed, randomGreen, randomBlue, 1.0f);
}
