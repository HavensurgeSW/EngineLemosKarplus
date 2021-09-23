#pragma once
#include "Exports.h"
//#define Red Color(1, 0, 0) define colors like this?

struct FLK_API Color
{
	float r;
	float g;
	float b;
	float a;

	Color();
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);

	static Color Red();
	static Color Green();
	static Color Blue();
	static Color Yellow();
	static Color Black();
	static Color White();
	static Color Purple();
	static Color Clear();

	static Color RandomRedShade();
	static Color RandomGreenShade();
	static Color RandomBlueShade();
	static Color RandomColor();
};