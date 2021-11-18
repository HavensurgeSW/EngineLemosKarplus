#ifndef COLOR_H
#define COLOR_H

#include "Exports.h"

struct FLK_API Color
{
	float r;
	float g;
	float b;
	float a;

	Color();
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);

	void TurnNegative();
	Color GetNegative();

	static Color Red();
	static Color Green();
	static Color Blue();

	static Color Lime();
	static Color Yellow();
	static Color Black();
	static Color White();
	static Color Maroon();
	static Color Cyan();
	static Color Orange();
	static Color Teal();
	static Color Purple();
	static Color Gray();
	static Color Silver();
	static Color Fuchsia();
	static Color Pink();
	static Color OldPink();
	static Color Clear();

	static Color GetNegative(Color color);

	static Color RandomRedShade();
	static Color RandomGreenShade();
	static Color RandomBlueShade();
	static Color RandomColor();
};

#endif