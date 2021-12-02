#ifndef ANIMATION_H
#define ANIMATION_H

#include "Exports.h"

#include "Vector4.h"
#include <iostream>
#include <vector>

class FLK_API Animation
{
private:

	std::string animationName;

	Vector4 uvs;
	Vector2 dimensions;

	int currentFrame;
	int maxFrames;

	int firstIndex;
	int lastIndex;

	float length;
	float time;

	void ChangeFrame();
	Vector4 GetUVs(int index);
	int GetCurrentFrame();

public:

	Animation();
	~Animation();

	void SetInfomation(/* EXPAND */);

	void SetName(std::string name);
	std::string GetName() const;

	void InitSpriteSheetDimensions(const Vector2& tileDimensions);
	void AddFrame(float durationInSeconds, int firstIndex, int lastIndex);
	void UpdateFrame();
	Vector4 GetFrames();
};

#endif