#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>



class Window
{
private:
	const char *m_Title;
	int m_Width, m_Height;
	GLFWwindow *m_Window;

	GLfloat m_LastFrame;
	GLfloat m_DeltaTime;
	GLfloat m_CurrentFrame;

	glm::vec4 m_BackgroundColor;

public:
	Window(const char *name, int width, int height);
	~Window();
	void clear() const;
	void update();
	void close();
	
	void setBackgroundColor(glm::vec3 color);

	inline GLFWwindow* getWindow() const { return m_Window; }
	inline GLfloat deltaTime() const { return m_DeltaTime; }
	inline bool shouldClose() const { return glfwWindowShouldClose(m_Window); }

private:
	bool Init();
	
};