#include "Vector3.h"

#include "Vector2.h"

#include <string>

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


void Vector3::SetValues(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::Cross(Vector3 otherVector)
{
	Vector3 result;
	result.x = y * otherVector.z - (otherVector.y * z);
	result.y = -(x * otherVector.z - (otherVector.x * z));
	result.z = x * otherVector.y - (otherVector.x * y);
	return result;
}

float Vector3::Dot(Vector3 otherVector)
{
	return (x * otherVector.x) + (y * otherVector.y) + (z * otherVector.z);
}

Vector3 Vector3::Normalize()
{
	float sqRoot = sqrt(x * x + y * y + z * z);
	if (sqRoot != 0)
	{
		x /= sqRoot;
		y /= sqRoot;
		z /= sqRoot;
	}
	return Vector3(x, y, z);
}


Vector3 Vector3::Zero()
{
	return Vector3(0.0f, 0.0f, 0.0f);
}

Vector3 Vector3::One()
{
	return Vector3(1.0f, 1.0f, 1.0f);
}

Vector3 Vector3::Up()
{
	return Vector3(0.0f, 1.0f, 0.0f);
}

Vector3 Vector3::Down()
{
	return Vector3(0.0f, -1.0f, 0.0f);
}

Vector3 Vector3::Right()
{
	return Vector3(1.0f, 0.0f, 0.0f);
}

Vector3 Vector3::Left()
{
	return Vector3(-1.0f, 0.0f, 0.0f);
}

Vector3 Vector3::Foward()
{
	return Vector3(0.0f, 0.0f, -1.0f);
}

Vector3 Vector3::Back()
{
	return Vector3(0.0f, 0.0f, 1.0f);
}


Vector3 Vector3::operator +(const Vector2& otherVector) const
{
	return Vector3(x + otherVector.x, y + otherVector.y, z);
}

Vector3 Vector3::operator -(const Vector2& otherVector) const
{
	return Vector3(x - otherVector.x, y - otherVector.y, z);
}


Vector3 Vector3::operator +(const Vector3& otherVector) const
{
	return Vector3(x + otherVector.x, y + otherVector.y, z + otherVector.z);
}

Vector3 Vector3::operator -(const Vector3& otherVector) const
{
	return Vector3(x - otherVector.x, y - otherVector.y, z - otherVector.z);
}


Vector3 Vector3::operator *(const float scalar) const
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator /(const float scalar) const
{
	return Vector3(x / scalar, y / scalar, z / scalar);
}

bool Vector3::operator ==(const Vector3& otherVector) const
{
	return x == otherVector.x && y == otherVector.y && z == otherVector.z;
}

Vector3 Vector3::operator+=(const Vector3& otherVector)
{
	x += otherVector.x;
	y += otherVector.y;
	z += otherVector.z;
	return Vector3(x, y, z);
}

std::string Vector3::ToString() const
{
	std::string vectorData = "X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z);
	return vectorData;
}