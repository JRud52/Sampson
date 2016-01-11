#include "vec4.h"

namespace sampson { namespace math {

	vec4::vec4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	vec4::vec4(const float x, const float y, const float z, const float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4 vec4::operator+=(const vec4& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	vec4 vec4::operator-=(const vec4& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	vec4 vec4::operator*=(const vec4& vector)
	{
		x *= vector.x;
		y *= vector.y;
		z *= vector.z;
		w *= vector.w;
		return *this;
	}

	vec4 vec4::operator/=(const vec4& vector)
	{
		x /= vector.x;
		y /= vector.y;
		z /= vector.z;
		w /= vector.w;
		return *this;
	}

	vec4 vec4::operator+(const vec4& vector)
	{
		vec4 vec = *this;
		vec.x += vector.x;
		vec.y += vector.y;
		vec.z += vector.z;
		vec.w += vector.w;
		return vec;
	}

	vec4 vec4::operator-(const vec4& vector)
	{
		vec4 vec = *this;
		vec.x -= vector.x;
		vec.y -= vector.y;
		vec.z -= vector.z;
		vec.w -= vector.w;
		return vec;
	}

	vec4 vec4::operator*(const vec4& vector)
	{
		vec4 vec = *this;
		vec.x *= vector.x;
		vec.y *= vector.y;
		vec.z *= vector.z;
		vec.w *= vector.w;
		return vec;
	}

	vec4 vec4::operator/(const vec4& vector)
	{
		vec4 vec = *this;
		vec.x /= vector.x;
		vec.y /= vector.y;
		vec.z /= vector.z;
		vec.w /= vector.w;
		return vec;
	}

	bool vec4::operator==(const vec4& vector)
	{
		return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
	}

	bool vec4::operator!=(const vec4& vector)
	{
		return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
	}

	std::ostream& operator<<(std::ostream& stream, const vec4& vector)
	{
		stream << "(" << vector.x << ", " << vector.y << ", "
			<< vector.z << ", " << vector.w << ")";
		return stream;
	}

} }