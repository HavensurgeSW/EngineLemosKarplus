#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include "Exports.h"

class FLK_API Shape
{
private:
	float positions[8];

public:
	Shape();
	~Shape();

	void SetPositions(float *arr);
};


// Las matrices copadas son: Model, View, Projection
