#include "input.h"

bool Input::m_Keys[MAX_KEYS];
bool Input::m_MouseButtons[MAX_BUTTONS];
double Input::m_mouseX;
double Input::m_mouseY;

//construct the input object
Input::Input(Window* window)
{
	Init();
	glfwSetKeyCallback(window->getWindow(), key_callback);
	glfwSetMouseButtonCallback(window->getWindow(), mouse_button_callback);
	glfwSetCursorPosCallback(window->getWindow(), cursor_position_callback);
}

//destroy the input object
Input::~Input()
{

}

//initialize the input object
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

//set key to true if pressed
bool Input::isKeyPressed(unsigned int keycode) const
{
	//TODO log this!
	if (keycode >= MAX_KEYS)
		return false;

	return m_Keys[keycode];
}

//set mouse button to true if pressed
bool Input::isMouseButtonPressed(unsigned int button) const
{
	//TODO log this!
	if (button >= MAX_BUTTONS)
		return false;

	return m_MouseButtons[button];
}

//get the mouse position
void Input::getMousePosition(double& x, double& y) const
{
	x = m_mouseX;
	y = m_mouseY;
}

//called when key is pressed
void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Input::m_Keys[key] = action != GLFW_RELEASE;
}

//called when mouse button is pressed
void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	m_MouseButtons[button] = action != GLFW_RELEASE;
}

//called when cursor is moved
void Input::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	m_mouseX = xpos;
	m_mouseY = ypos;
}
