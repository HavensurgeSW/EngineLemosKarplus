#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include "Exports.h"
#include "Entity2D.h"
#include "Window.h"

class FLK_API Shape : public Entity2D
{
private:
    float* _vertexBuffer;
    unsigned int _vbo;
    unsigned int _currentShape;
    unsigned int _posAttrib;
    unsigned int _colorAttrib;

public:
    Shape(Renderer* _renderer);
    Shape(Renderer _renderer);
    ~Shape();
    void InitShape(unsigned int typeShape);
    void CreateVbo(float* vertexBuffer);
    unsigned int GetVbo();
    float* GetVertexBuffer();
    void SetVertexsAttrib(unsigned int& shaderId);
    unsigned int GetPosAttrib();
    unsigned int GetColAttrib();
    void Draw(unsigned int figura, int vertexs, unsigned int& shaderProg, Window* refWindow, glm::mat4 model);
};
// Las matrices copadas son: Model, View, Projection
