#include "input.h"

bool Input::m_Keys[MAX_KEYS];
bool Input::m_MouseButtons[MAX_BUTTONS];
double Input::m_mouseX;
double Input::m_mouseY;

Input::Input(Window* window)
{
	Init();
	glfwSetKeyCallback(window->getWindow(), key_callback);
	glfwSetMouseButtonCallback(window->getWindow(), mouse_button_callback);
	glfwSetCursorPosCallback(window->getWindow(), cursor_position_callback);
}

Input::~Input()
{

}

bool Input::Init() 
{
	for (int i = 0; i < MAX_KEYS; i++)
	{
		m_Keys[i] = false;
	}

	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		m_MouseButtons[i] = false;
	}
	return true;
}

bool Input::isKeyPressed(unsigned int keycode) const
{
	//TODO log this!
	if (keycode >= MAX_KEYS)
		return false;

	return m_Keys[keycode];
}

bool Input::isMouseButtonPressed(unsigned int button) const
{
	//TODO log this!
	if (button >= MAX_BUTTONS)
		return false;

	return m_MouseButtons[button];
}

void Input::getMousePosition(double& x, double& y) const
{
	x = m_mouseX;
	y = m_mouseY;
}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Input::m_Keys[key] = action != GLFW_RELEASE;
}

void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	m_MouseButtons[button] = action != GLFW_RELEASE;
}

void Input::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	m_mouseX = xpos;
	m_mouseY = ypos;
}
