#pragma once
#include <iostream>
#include "Vector2.h"

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float x, float y, float z);

	void SetValues(float x, float y, float z);

	static Vector3 Zero();
	static Vector3 One();
	static Vector3 Up();
	static Vector3 Down();
	static Vector3 Right();
	static Vector3 Left();
	static Vector3 Foward();
	static Vector3 Back();

	Vector3 operator +(const Vector2& otherVector) const;
	Vector3 operator -(const Vector2& otherVector) const;

	Vector3 operator +(const Vector3& otherVector) const;
	Vector3 operator -(const Vector3& otherVector) const;
	Vector3 operator *(const float scalar) const;
	Vector3 operator /(const float scalar) const;
	bool operator ==(const Vector3& otherVector) const;
	std::string ToString() const;
};