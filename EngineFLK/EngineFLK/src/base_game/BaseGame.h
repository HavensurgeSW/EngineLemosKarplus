#pragma once

#include "Exports.h"
#include "window/Window.h"
#include "renderer/Renderer.h"
#include "input/Input.h"
#include "collision_manager/CollisionManager.h"
#include "entities/entity/Entity.h"

class FLK_API BaseGame
{
private:
	Window* window; //Mover GLFWWindow a constructor
	Renderer* renderer;
	Input* input;
	CollisionManager* collisionManager;
	Entity* entity;

public:
	BaseGame();
	~BaseGame();

	void LaunchGod();
	void Terminate();
};
