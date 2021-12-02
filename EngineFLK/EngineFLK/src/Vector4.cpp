#include "Vector4.h"

#include <string>

#include "Vector2.h"
#include "Vector3.h"

Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void Vector4::SetValues(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

float Vector4::Dot(Vector4 otherVector)
{
	return x * otherVector.x + y * otherVector.y + z * otherVector.z + w * otherVector.w;
}

Vector4 Vector4::Normalize()
{
	float sqRoot = sqrt(Dot(*this));
	if (sqRoot != 0)
	{
		x /= sqRoot;
		y /= sqRoot;
		z /= sqRoot;
		w /= sqRoot;
	}
	return Vector4(x, y, z, w);
}

Vector4 Vector4::Zero()
{
	return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
}

Vector4 Vector4::One()
{
	return Vector4(1.0f, 1.0f, 1.0f, 1.0f);
}

Vector4 Vector4::operator+(const Vector2& otherVector) const
{
	return Vector4(x + otherVector.x, y + otherVector.y, z, w);
}

Vector4 Vector4::operator-(const Vector2& otherVector) const
{
	return Vector4(x - otherVector.x, y - otherVector.y, z, w);
}

Vector4 Vector4::operator+(const Vector3& otherVector) const
{
	return Vector4(x + otherVector.x, y + otherVector.y, z + otherVector.z, w);
}

Vector4 Vector4::operator-(const Vector3& otherVector) const
{
	return Vector4(x - otherVector.x, y - otherVector.y, z - otherVector.z, w);
}

Vector4 Vector4::operator+(const Vector4& otherVector) const
{
	return Vector4(x + otherVector.x, y + otherVector.y, z + otherVector.z, w + otherVector.w);
}

Vector4 Vector4::operator-(const Vector4& otherVector) const
{
	return Vector4(x - otherVector.x, y - otherVector.y, z - otherVector.z, w - otherVector.w);
}

Vector4 Vector4::operator*(const float scalar) const
{
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 Vector4::operator/(const float scalar) const
{
	return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

bool Vector4::operator==(const Vector4& otherVector) const
{
	return x == otherVector.x && y == otherVector.y && z == otherVector.z && w == otherVector.w;
}

Vector4 Vector4::operator+=(const Vector4& otherVector)
{
	return Vector4(x + otherVector.x, y + otherVector.y, z + otherVector.z, w + otherVector.w);
}

std::string Vector4::ToString() const
{
	std::string vectorData = "X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z) + " W: " + std::to_string(w);
	return vectorData;
}
