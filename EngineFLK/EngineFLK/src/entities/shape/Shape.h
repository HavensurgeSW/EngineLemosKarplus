#pragma once

#include "Exports.h"
#include "renderer/Renderer.h"
#include "shader/Shader.h"

#include <iostream>
#include <iterator>
#include <vector>

enum class FLK_API ShapeType //Primitive?
{
	TRIANGLE,
	QUAD
};

class FLK_API Shape
{
private:
	Renderer* renderer;
	ShapeType type;
	Shader shader;
	float positions[8];

public:
	Shape();
	Shape(Renderer* renderer, Shader shader);
	Shape(Renderer* renderer, Shader shader, ShapeType type);
	~Shape();

	void SetRenderer(Renderer* renderer);
	void SetShader(Shader shader);
	void SetShapeType(ShapeType type);
	void Draw();

	void SetPositions(float *arr);
};


// Las matrices copadas son: Model, View, Projection
