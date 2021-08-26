#pragma once


#include "CollisionManager.h"
#include "Input.h"
#include "Renderer.h"
#include "Window.h"

#include "glew.h"
#include "glfw3.h"

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
    void launchGodTest();
    void terminate();
};
