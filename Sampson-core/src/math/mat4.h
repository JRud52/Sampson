#pragma once

#include "math.h"

namespace sampson { namespace math {

	struct mat4
	{
		float elements[16];

		mat4();
		mat4(float diagonal);

		static mat4 identity();

		mat4 multiply(const mat4& mat);
		mat4 operator*(const mat4& mat);
		mat4 operator*=(const mat4& mat);

		static mat4 orthographic(float left, float right, float top, float bottom,
			float near, float far);
		static mat4 perspective(float fov, float aspectRatio, float near, float far);

		static mat4 translation(const vec3& translation);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);

		

	};

} }