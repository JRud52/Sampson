#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

namespace sampson { namespace shaders {

	class Shader
	{
	public:
		GLuint Program;
		// Constructor generates the shader on the fly
		Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
		void Use();
	};

} }