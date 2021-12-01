#ifndef ANIMATION_H
#define ANIMATION_H

#include "Exports.h"

#include <iostream>

class FLK_API Animation
{
private:

	std::string animationName;
	unsigned int frameCount;

public:
	Animation();
	~Animation();

	void SetInfomation(/* EXPAND */);

	void SetName(std::string name);
	std::string GetName() const;
};

#endif