#ifndef VECTOR3_H
#define VECTOR3_H

#include "Exports.h"

#include <iostream>

struct Vector2;

struct FLK_API Vector3
{
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float x, float y, float z);

	void SetValues(float x, float y, float z);
	Vector3 Cross(Vector3 otherVector);
	float Dot(Vector3 otherVector);
	Vector3 Normalize();

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
	Vector3 operator +=(const Vector3& otherVector);

	std::string ToString() const;
};

#endif