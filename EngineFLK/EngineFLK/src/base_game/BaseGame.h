#pragma once

#include "window/Window.h"
#include "renderer/Renderer.h"
#include "input/Input.h"
#include "collision_manager/CollisionManager.h"

#include <iostream>

//Wrong, should not be here. Create shader class?
struct ShaderPaths {
    std::string vertexSource;
    std::string fragmentSource;
};

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
    static ShaderPaths ParseShader(const std::string& filepath);
};
