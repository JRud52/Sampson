#include "shader.h"

//initialize the shader
Shader::Shader(const char* vertPath, const char* fragPath)
	: m_VertPath(vertPath), m_FragPath(fragPath)
{
	m_ShaderID = load();
}

//free up memory
Shader::~Shader()
{
	glDeleteProgram(m_ShaderID);
}

//load the shader
GLuint Shader::load()
{
	GLuint program = glCreateProgram();
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

	//read in the shader files
	std::string vertSourceString = FileUtils::read_file(m_VertPath);
	std::string fragSourceString = FileUtils::read_file(m_FragPath);
	const char* vertSource = vertSourceString.c_str();
	const char* fragSource = fragSourceString.c_str();

	//compile vertex shader
	glShaderSource(vertex, 1, &vertSource, NULL);
	glCompileShader(vertex);

	GLint result;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(vertex, length, &length, &error[0]);
		std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
		glDeleteShader(vertex);
		return 0;
	}

	//compile fragment shader
	glShaderSource(fragment, 1, &fragSource, NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(fragment, length, &length, &error[0]);
		std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
		glDeleteShader(fragment);
		return 0;
	}

	//attach shaders to program
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	//link the shader program
	glLinkProgram(program);
	glValidateProgram(program);

	//free up memory
	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}

//use the shader program
void Shader::enable() const
{
	glUseProgram(m_ShaderID);
}

//reset shader program
void Shader::disable() const
{
	glUseProgram(0);
}

//set uniform functions 
void Shader::setUniform1f(const GLchar* name, float value)
{
	glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform2f(const GLchar* name, glm::vec2& vector)
{
	glUniform2f(getUniformLocation(name), vector.x, vector.y);
}

void Shader::setUniform3f(const GLchar* name, glm::vec3& vector)
{
	glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}

void Shader::setUniform4f(const GLchar* name, glm::vec4& vector)
{
	glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}

void Shader::setUniform1i(const GLchar* name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}

void Shader::setUniformMat4(const GLchar* name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

GLint Shader::getUniformLocation(const GLchar* name)
{
	return glGetUniformLocation(m_ShaderID, name);
}
