#pragma once

#include "Exports.h"
#include "Window.h"
#include "Renderer.h"
#include "Input.h"
#include "CollisionManager.h"
#include "Entity.h"

class FLK_API BaseGame
{
private:
	Window* window; //Mover GLFWWindow a constructor
	Renderer* renderer;
	Input* input;
	CollisionManager* collisionManager;
	Entity* entity;
	Shader shader;
	void TempInputs(Window* window);

public:
	BaseGame();
	~BaseGame();

	void InitEngine();
	void LaunchGod();
	void Terminate();
};
