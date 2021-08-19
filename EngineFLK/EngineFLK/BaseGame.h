#pragma once
#include <GLFW\glfw3.h>
#include "CollisionManager.h"
#include "Input.h"
#include "Renderer.h"
#include "Window.h"
#include <iostream>

class BaseGame{
private:
    Window* w;
    Renderer* r;
    Input* i;
    CollisionManager* cm;
public:
    void launchGod();
};




