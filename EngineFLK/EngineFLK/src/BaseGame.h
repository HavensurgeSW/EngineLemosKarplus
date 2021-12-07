#ifndef BASE_GAME_H
#define BASE_GAME_H

#include "Exports.h"
#include "Window.h"
#include "Renderer.h"
#include "Input.h"
#include "CollisionManager.h"
#include "TimeManager.h"
#include "Color.h"

class FLK_API BaseGame
{
private:
	Window* window;
	Renderer* renderer;
	Input* input;
	CollisionManager* collisionManager;

	TimeManager time;
protected:

	//Renderer* GetRenderer() const;
	CollisionManager* GetCollisionManager() const;

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

#endif