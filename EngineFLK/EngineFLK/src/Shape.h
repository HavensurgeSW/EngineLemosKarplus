#pragma once

#include "Exports.h"
#include "Renderer.h"
#include "Shader.h"
#include "Entity2D.h"

#include <iostream>
#include <iterator>
#include <vector>

enum FLK_API ShapeType //Primitive?
{
	TRIANGLE,
	QUAD
};

class FLK_API Shape : public Entity2D
{
private:
	Renderer* renderer;
	ShapeType type;
	Shader shader;

public:
	Shape();
	Shape(Renderer* renderer, Shader shader);
	Shape(Renderer* renderer, Shader shader, ShapeType type);
	~Shape();

	void SetRenderer(Renderer* renderer);
	void SetShader(Shader shader);
	void SetShapeType(ShapeType type);
	void Draw();
};
