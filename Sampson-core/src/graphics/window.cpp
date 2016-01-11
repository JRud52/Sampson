#include "window.h"

namespace sampson { namespace graphics {

	void window_resize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height)
	{
		m_Title = title;
		m_Height = height;
		m_Width = width;
		if (!Init())
			glfwTerminate();
	}

	Window::~Window() 
	{
		glfwTerminate();
	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);


		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;
		}

		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		m_deltaTime = 0.0f;
		m_lastFrame = 0.0f;
		m_currentFrame = 0.0f;

		return true;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		m_currentFrame = glfwGetTime();
		m_deltaTime = m_currentFrame - m_lastFrame;
		m_lastFrame = m_currentFrame;

		glfwSwapBuffers(m_Window);
	}
	
	void Window::close()
	{
		glfwSetWindowShouldClose(m_Window, GL_TRUE);
		m_Close = true;
	}

	void window_resize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

} }