#ifndef ANIMATION_H
#define ANIMATION_H

#include "Exports.h"

#include "Vector2.h"
#include "Vector4.h"

#include <iostream>
#include <vector>

struct FLK_API AnimationData
{
	std::string animationName;
	float animationDuration;

	int framesPerRow;
	int framesPerCollumn;

	int startingFrame;
	int finalFrame;

	bool loop;
};

class FLK_API Animation
{
private:

	struct Frame 
	{
		Vector4 uvs;
	};

	friend class AnimatedSprite;
	
	std::string animationName;

	Vector2 dimensions;

	std::vector<Frame> frames;
	Frame currentFrame;

	int currentFrameIndex;

	int firstIndex;
	int lastIndex;

	float frameDuration;
	float timer;

	bool loop;
	bool stop;

public:

	Animation();
	~Animation();

	void SetName(std::string name);
	std::string GetName() const;

	void InitSpriteSheetDimensions(const Vector2& tileDimensions);
	void AddFrame(float animationDuration, int firstIndex, int lastIndex);
	void SetLoopStatus(bool loop);

	void Reset();
	void Stop();

	Vector4 GetFrames() const;

private:
	void UpdateAnimation();
	void SetCurrentFrame(int index);
};

#endif