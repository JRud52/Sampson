#include "vec2.h"



vec2::vec2()
{
	x = 0.0f;
	y = 0.0f;
}

vec2::vec2(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

vec2 vec2::operator+=(const vec2& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

vec2 vec2::operator-=(const vec2& vector)
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}

vec2 vec2::operator*=(const vec2& vector)
{
	x *= vector.x;
	y *= vector.y;
	return *this;
}

vec2 vec2::operator/=(const vec2& vector)
{
	x /= vector.x;
	y /= vector.y;
	return *this;
}

vec2 vec2::operator+(const vec2& vector)
{
	vec2 vec = *this;
	vec.x += vector.x;
	vec.y += vector.y;
	return vec;
}

vec2 vec2::operator-(const vec2& vector)
{
	vec2 vec = *this;
	vec.x -= vector.x;
	vec.y -= vector.y;
	return vec;
}

vec2 vec2::operator*(const vec2& vector)
{
	vec2 vec = *this;
	vec.x *= vector.x;
	vec.y *= vector.y;
	return vec;
}

vec2 vec2::operator/(const vec2& vector)
{
	vec2 vec = *this;
	vec.x /= vector.x;
	vec.y /= vector.y;
	return vec;
}

bool vec2::operator==(const vec2& vector)
{
	return x == vector.x && y == vector.y;
}

bool vec2::operator!=(const vec2& vector)
{
	return x != vector.x || y != vector.y;
}

std::ostream& operator<<(std::ostream& stream, const vec2& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ")";
	return stream;
}

