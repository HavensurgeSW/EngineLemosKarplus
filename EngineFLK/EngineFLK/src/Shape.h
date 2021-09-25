#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include "Exports.h"
#include "Entity2D.h"

class FLK_API Shape : public Entity2D
{
private:
	float positions[8];

public:
	Shape();
	~Shape();

	void SetPositions(float *arr);
};


// Las matrices copadas son: Model, View, Projection
