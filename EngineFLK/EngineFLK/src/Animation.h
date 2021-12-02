#ifndef ANIMATION_H
#define ANIMATION_H

#include "Exports.h"

#include "Vector2.h"
#include "Vector4.h"

#include <iostream>
#include <vector>

class FLK_API Animation
{
private:

	struct Frame 
	{
		Vector4 uvs;
	};

	std::string animationName;

	Vector2 dimensions;

	int currentFrameIndex;
	int firstIndex;
	int lastIndex;

	float frameDuration;
	float time;

	std::vector<Frame> frames;
	Frame currentFrame;

public:

	Animation();
	~Animation();

	void SetInfomation(/* EXPAND */);

	void SetName(std::string name);
	std::string GetName() const;

	void InitSpriteSheetDimensions(const Vector2& tileDimensions);
	void AddFrame(float animationDuration, int firstIndex, int lastIndex);

	void UpdateFrame();
	Vector4 GetFrames() const;

private:
	void SetCurrentFrame(int index);
};

#endif