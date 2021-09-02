#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Input.h"
#include "CollisionManager.h"

#include <iostream>

class BaseGame 
{
private:
    Window* window; //Mover GLFWWindow a constructor
    Renderer* renderer;
    Input* input;
    CollisionManager* collisionManager;

public:
    BaseGame();
    ~BaseGame();
    
    void LaunchGod();
    void Terminate();
    static unsigned int CreateShader(const std::string& vertexShader, const std::string fragmentShader);
    static unsigned int CompileShader(const std::string& source, unsigned int type);
};
