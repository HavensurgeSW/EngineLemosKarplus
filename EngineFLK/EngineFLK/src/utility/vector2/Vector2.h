#pragma once

#include <iostream>

struct Vector2
{
	float x = 0;
	float y = 0;

	Vector2();
	Vector2(float x, float y);

	void SetValues(float x, float y);
	float Dot(const Vector2 otherVector);
	Vector2 Cross(const Vector2 otherVector);
	Vector2 Normalize();

	static Vector2 Zero();
	static Vector2 One();
	static Vector2 Up();
	static Vector2 Down();
	static Vector2 Right();
	static Vector2 Left();

	Vector2 operator +(const Vector2& otherVector) const;
	Vector2 operator -(const Vector2& otherVector) const;
	bool operator ==(const Vector2& otherVector) const;
	Vector2 operator *(const float scalar) const;
	Vector2 operator /(const float scalar) const;
	std::string ToString() const;
};