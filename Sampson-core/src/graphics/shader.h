#pragma once

#include "../utils/fileutils.h"
#include <GL/glew.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

class Shader
{
private:
	GLuint m_ShaderID;
	const char* m_VertPath;
	const char* m_FragPath;
public:
	Shader(const char* vertPath, const char* fragPath);
	~Shader();

	void setUniform1f(const GLchar* name, float value);
	void setUniform2f(const GLchar* name, glm::vec2& vector);
	void setUniform3f(const GLchar* name, glm::vec3& vector);
	void setUniform4f(const GLchar* name, glm::vec4& vector);

	void setUniform1i(const GLchar* name, int value);

	void setUniformMat4(const GLchar* name, const glm::mat4& matrix);

	void enable() const;
	void disable() const;

	GLuint getProgram() { return m_ShaderID; };

private:
	GLuint load();
	GLint getUniformLocation(const GLchar* name);

};