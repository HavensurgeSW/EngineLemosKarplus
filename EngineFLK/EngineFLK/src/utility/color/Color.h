#pragma once

//#define Red Color(1, 0, 0) define colors like this?

struct Color 
{
	float r;
	float g;
	float b;
	float a;

	Color();
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);

	//Color Red(); or like this?
	//Add random color?
};