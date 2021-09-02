#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Input.h"
#include "CollisionManager.h"

#include <iostream>

class BaseGame {
private:
    Window* _window; //Mover GLFWWindow a constructor
    Renderer* _renderer;
    Input* _input;
    CollisionManager* _collisionManager;

public:
    BaseGame();
    ~BaseGame();
    
    void launchGod();
    void terminate();
    static unsigned int createShader(const std::string& vertexShader, const std::string fragmentShader);
    static unsigned int compileShader(const std::string& source, unsigned int type);
};
