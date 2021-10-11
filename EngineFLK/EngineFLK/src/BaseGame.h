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
	Window* window;
	Renderer* renderer;
	Input* input;
	CollisionManager* collisionManager;
	Entity* entity;
	Shader shader;

public:
	BaseGame();
	~BaseGame();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void DeInit() = 0;

	void InitEngine();
	void LaunchGod();
	void Terminate();

private:

	void InitGlew();
};
