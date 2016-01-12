#include "vec3.h"



vec3::vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

vec3::vec3(const float x, const float y, const float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3 vec3::operator+=(const vec3& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

vec3 vec3::operator-=(const vec3& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

vec3 vec3::operator*=(const vec3& vector)
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
	return *this;
}

vec3 vec3::operator/=(const vec3& vector)
{
	x /= vector.x;
	y /= vector.y;
	z /= vector.z;
	return *this;
}

vec3 vec3::operator+(const vec3& vector)
{
	vec3 vec = *this;
	vec.x += vector.x;
	vec.y += vector.y;
	vec.z += vector.z;
	return vec;
}

vec3 vec3::operator-(const vec3& vector)
{
	vec3 vec = *this;
	vec.x -= vector.x;
	vec.y -= vector.y;
	vec.z -= vector.z;
	return vec;
}

vec3 vec3::operator*(const vec3& vector)
{
	vec3 vec = *this;
	vec.x *= vector.x;
	vec.y *= vector.y;
	vec.z *= vector.z;
	return vec;
}

vec3 vec3::operator/(const vec3& vector)
{
	vec3 vec = *this;
	vec.x /= vector.x;
	vec.y /= vector.y; 
	vec.z /= vector.z;
	return vec;
}

bool vec3::operator==(const vec3& vector)
{
	return x == vector.x && y == vector.y && z == vector.z;
}

bool vec3::operator!=(const vec3& vector)
{
	return x != vector.x || y != vector.y || z != vector.z;
}

std::ostream& operator<<(std::ostream& stream, const vec3& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ")";
	return stream;
}

