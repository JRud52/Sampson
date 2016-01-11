#include "mat4.h"

namespace sampson { namespace math {

	mat4::mat4()
	{
		for (int i = 0; i < 16; i++)
			elements[i] = 0.0f;
	}

	mat4::mat4(float diagonal)
	{
		for (int i = 0; i < 16; i++)
			elements[i] = 0.0f;
		elements[0]		= diagonal;
		elements[5]		= diagonal;
		elements[10]	= diagonal;
		elements[15]	= diagonal;
	}

	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}

	mat4 mat4::multiply(const mat4&)
	{
		mat4 result;
	}

} }