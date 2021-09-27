#pragma once
#include "BaseGame.h"
#include <vector>

class Game : public BaseGame
{
private:
	std::vector<Shape*> shapes;

public:

	Game();
	~Game();

	void Init() override;
	void Update() override;
	void DeInit() override;
};

