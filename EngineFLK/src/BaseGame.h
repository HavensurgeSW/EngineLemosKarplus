#pragma once
#include <GLFW\glfw3.h>
#include "CollisionManager.h"
#include "Input.h"
#include "Renderer.h"
#include "Window.h"
#include <iostream>

class BaseGame{
private:
    Window* _window;
    Renderer* _renderer;
    Input* _input;
    CollisionManager* _collisionManager;
public:
    void launchGod();
};




