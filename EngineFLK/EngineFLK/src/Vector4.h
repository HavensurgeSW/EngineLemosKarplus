#ifndef VECTOR4_H
#define VECTOR4_H

#include "Exports.h"

#include <iostream>

class Vector2;
class Vector3;

struct FLK_API Vector4
{
	float x;
	float y;
	float z;
	float w;

	Vector4();
	Vector4(float x, float y, float z, float w);

	void SetValues(float x, float y, float z, float w);
	float Dot(Vector4 otherVector);
	Vector4 Normalize();

	static Vector4 Zero();
	static Vector4 One();

	Vector4 operator +(const Vector2& otherVector) const;
	Vector4 operator -(const Vector2& otherVector) const;
	Vector4 operator +(const Vector3& otherVector) const;
	Vector4 operator -(const Vector3& otherVector) const;

	Vector4 operator +(const Vector4& otherVector) const;
	Vector4 operator -(const Vector4& otherVector) const;
	Vector4 operator *(const float scalar) const;
	Vector4 operator /(const float scalar) const;
	bool operator ==(const Vector4& otherVector) const;
	Vector4 operator +=(const Vector4& otherVector);

	std::string ToString() const;
};

#endif