#include "window.h"

void window_resize(GLFWwindow *window, int width, int height);

//construct the window
Window::Window(const char *title, int width, int height)
{
	m_Title = title;
	m_Height = height;
	m_Width = width;
	m_BackgroundColor = glm::vec4(0, 0, 0, 1.0f);
	if (!Init())
		glfwTerminate();
}

//terminate glfw on window close
Window::~Window() 
{
	glfwTerminate();
}

//initialize the window
bool Window::Init()
{
	//initialize glfw
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return false;
	}

	//create window
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (!m_Window)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		return false;
	}

	//set context and callback
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetWindowSizeCallback(m_Window, window_resize);

	//set window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glewExperimental = GL_TRUE;

	//check if glew was initialized
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Could not initialize GLEW!" << std::endl;
		return false;
	}

	//print opengl version to console 
	std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

	//initialize deltatime
	m_DeltaTime = 0.0f;
	m_LastFrame = 0.0f;
	m_CurrentFrame = 0.0f;

	return true;
}

// clear the window color
void Window::clear() const
{
	glClearColor(m_BackgroundColor.x, m_BackgroundColor.y, m_BackgroundColor.z, m_BackgroundColor.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//update the window
void Window::update()
{
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "OpenGl Error: " << error << std::endl;

	//update deltatime
	glfwPollEvents();
	m_CurrentFrame = glfwGetTime();
	m_DeltaTime = m_CurrentFrame - m_LastFrame;
	m_LastFrame = m_CurrentFrame;

	glfwSwapBuffers(m_Window);
}

//close the window
void Window::close()
{
	glfwSetWindowShouldClose(m_Window, GL_TRUE);
}

//called when window is resized
void window_resize(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

//sets the background color
void Window::setBackgroundColor(glm::vec3 color)
{
	m_BackgroundColor = glm::vec4(color, 1.0f);
}
