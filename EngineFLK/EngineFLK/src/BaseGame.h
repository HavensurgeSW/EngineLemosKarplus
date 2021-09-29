#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Input.h"
#include "CollisionManager.h"
#include "Entity.h"
#include "Shape.h"
#include "Exports.h"

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

	void InitEngine();
	void LaunchGodEngine();
	void Terminate();
	void TempInputs(Window* window);

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void DeInit() = 0;
};
