#pragma once

#include <iostream>

namespace sampson { namespace math {

	struct vec4
	{
		float x, y, z, w;

		vec4();
		vec4(const float x, const float y, const float z, const float w);

		vec4 operator+(const vec4& vector);
		vec4 operator-(const vec4& vector);
		vec4 operator*(const vec4& vector);
		vec4 operator/(const vec4& vector);

		vec4 operator+=(const vec4& vector);
		vec4 operator-=(const vec4& vector);
		vec4 operator*=(const vec4& vector);
		vec4 operator/=(const vec4& vector);

		bool operator==(const vec4& vector);
		bool operator!=(const vec4& vector);

		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
	};

} }