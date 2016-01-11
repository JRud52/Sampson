#pragma once

#include <iostream>

namespace sampson { namespace math {

	struct vec2
	{
		float x, y;

		vec2();
		vec2(const float x, const float y);

		vec2 operator+(const vec2& vector);
		vec2 operator-(const vec2& vector);
		vec2 operator*(const vec2& vector);
		vec2 operator/(const vec2& vector);

		vec2 operator+=(const vec2& vector);
		vec2 operator-=(const vec2& vector);
		vec2 operator*=(const vec2& vector);
		vec2 operator/=(const vec2& vector);

		bool operator==(const vec2& vector);
		bool operator!=(const vec2& vector);

		friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
	};

} }