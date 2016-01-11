#pragma once

#include <iostream>

namespace sampson { namespace math {

	struct vec3
	{
		float x, y, z;

		vec3();
		vec3(const float x, const float y, const float z);

		vec3 operator+(const vec3& vector);
		vec3 operator-(const vec3& vector);
		vec3 operator*(const vec3& vector);
		vec3 operator/(const vec3& vector);

		vec3 operator+=(const vec3& vector);
		vec3 operator-=(const vec3& vector);
		vec3 operator*=(const vec3& vector);
		vec3 operator/=(const vec3& vector);

		bool operator==(const vec3& vector);
		bool operator!=(const vec3& vector);

		friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
	};

} }