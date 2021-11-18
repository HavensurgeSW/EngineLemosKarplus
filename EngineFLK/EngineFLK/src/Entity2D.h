#ifndef ENTITY2D_H
#define ENTITY2D_H

#include "Exports.h"
#include "Renderer.h"
#include <iostream>

class FLK_API Entity2D
{
protected:	
	Renderer* renderer;

public:
	Transform transform;
};

#endif