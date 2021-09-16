#include "Vector2.h"

#include <string>

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}


void Vector2::SetValues(float x, float y)
{
	this->x = x;
	this->y = y;
}


Vector2 Vector2::Zero()
{
	return Vector2(0.0f, 0.0f);
}

Vector2 Vector2::One()
{
	return Vector2(1.0f, 1.0f);
}

Vector2 Vector2::Up()
{
	return Vector2(0.0f, 1.0f);
}

Vector2 Vector2::Down()
{
	return Vector2(0.0f, -1.0f);
}

Vector2 Vector2::Right()
{
	return Vector2(1.0f, 0.0f);
}

Vector2 Vector2::Left()
{
	return Vector2(-1.0f, 0.0f);
}


Vector2 Vector2::operator +(const Vector2& otherVector) const
{
	return Vector2(x + otherVector.x, y + otherVector.y);
}

Vector2 Vector2::operator -(const Vector2& otherVector) const
{
	return Vector2(x - otherVector.x, y - otherVector.y);
}

bool Vector2::operator ==(const Vector2& otherVector) const
{
	return x == otherVector.x && y == otherVector.y;
}

Vector2 Vector2::operator *(const float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator /(const float scalar) const
{
	return Vector2(x / scalar, y / scalar);
}

std::string Vector2::ToString() const
{
	std::string vectorData = "X: " + std::to_string(x) + " Y: " + std::to_string(y);
	return vectorData;
}