#ifndef ANIMATION_H
#define ANIMATION_H

#include "Exports.h"

#include <iostream>
#include <vector>

#include "glm/glm.hpp"

using namespace glm;

struct Frame
{
	vec4 uv;
	int framesCount;
};

class FLK_API Animation
{
private:

	std::string animationName;

	vec4 uvs = vec4(0, 0, 0, 0);
	ivec2 dimensions;
	std::vector<Frame> frames;

	int currentFrame;
	int maxFrames;

	int firstIndex;
	int lastIndex;

	float length;
	float time;

	void ChangeFrame();
public:
	Animation();
	~Animation();

	void SetInfomation(/* EXPAND */);

	void SetName(std::string name);
	std::string GetName() const;

	void InitSpriteSheetDimensions(const glm::ivec2& tileDimensions);
	void AddFrame(float durationInSeconds, int firstIndex, int lastIndex);
	void UpdateFrame();
	vec4 GetUVs(int index);
	int GetCurrentFrame();
};

#endif