#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace sampson { namespace graphics {

	class Window
	{
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Close;

		GLfloat m_lastFrame;
		GLfloat m_deltaTime;
		GLfloat m_currentFrame;

	public:
		Window(const char *name, int width, int height);
		~Window();
		void clear() const;
		void update();
		void close();

		inline GLFWwindow* getWindow() const { return m_Window; }
		inline GLfloat deltaTime() const { return m_deltaTime; }
		inline bool shouldClose() const { return m_Close; }

	private:
		bool Init();
		
	};



} }