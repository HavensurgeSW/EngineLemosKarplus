#include "Shape.h"

float vertexBufferTri[] = {
    //X          Y         Z        R      G        B      A
    -0.5f , -0.5f , 0.0f, 0.0f , 0.0f ,0.0f, 1.0f,
     0.5f , -0.5f , 0.0f, 0.0f , 0.0f ,0.0f, 1.0f,
     0.0f ,  0.5f , 0.0f, 0.0f , 0.0f, 0.0f, 1.0f
};

float vertexBufferQuad[] = {
    //X          Y         Z        R      G        B      A
    -0.5f ,  0.5f , 0.0f, 0.0f , 0.0f , 0.0f, 1.0f,
    -0.5f , -0.5f , 0.0f, 0.0f , 0.0f , 0.0f, 1.0f, 
     0.5f , -0.5f , 0.0f, 0.0f , 0.0f , 0.0f, 1.0f,
     0.5f ,  0.5f , 0.0f, 0.0f , 0.0f , 0.0f, 1.0f
};

float ColorTri[]
{
    1.0f,0.0f,0.0f,1.0f,
    0.0f,1.0f,0.0f,1.0f,
    0.0f,0.0f,1.0f,1.0f,
};

float ColorQuad[]
{
    1.0f,0.0f,0.0f,1.0f,
    0.0f,1.0f,0.0f,1.0f,
    0.0f,0.0f,1.0f,1.0f,
    1.0f,0.0f,1.0f,1.0f,
};

Shape::Shape(Renderer* renderer) : Entity2D(renderer)
{
    this->renderer = renderer;
}
Shape::~Shape() {}

void Shape::InitShape(unsigned int typeShape)
{
    //material->SetMaterialValue()
    _currentShape = typeShape;
    switch (typeShape)
    {
    case GL_TRIANGLES:
        _vertexBuffer = vertexBufferTri;

        //material->SetMaterialValue(0.5f, 0.3f, 0.2f, 1.0f);
        //SetVertexMaterial(material->GetColorRGBA(), vertexBufferT

        break;
    case GL_QUADS:
        _vertexBuffer = vertexBufferQuad;

        break;
    }
    CreateVbo(_vertexBuffer);
}

void Shape::CreateVbo(float* vertexBuffer) {

    int tam = 0;
    while (vertexBuffer[tam] <= 1 && vertexBuffer[tam] >= -1) {
        tam++;
    }
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, tam * sizeof(float), vertexBuffer, GL_DYNAMIC_DRAW);
}

unsigned int Shape::GetVbo() {
    return _vbo;
}

float* Shape::GetVertexBuffer()
{
    return _vertexBuffer;
}

void Shape::SetVertexsAttrib(unsigned int& shaderId) 
{
    _posAttrib = glGetAttribLocation(shaderId, "position");
    glVertexAttribPointer(_posAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
    glEnableVertexAttribArray(_posAttrib);
    _colorAttrib = glGetAttribLocation(shaderId, "customColor");
    glVertexAttribPointer(_colorAttrib, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(_colorAttrib);
}

unsigned int Shape::GetPosAttrib() {
    return _posAttrib;
}

unsigned int Shape::GetColAttrib() {
    return _colorAttrib;
}

void Shape::Draw(unsigned int figura, int vertexs, unsigned int& shaderProg, Windows* refWindow, glm::mat4 model)
{
    if (renderer != NULL)
    {
        renderer->BeignDraw();

        renderer->Draw(figura, vertexs, GetVbo(), shaderProg, GetPosAttrib(), GetColAttrib(), model);

        renderer->EndDraw(refWindow);
    }
    _currentShape = figura;
}