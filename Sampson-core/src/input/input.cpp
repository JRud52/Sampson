#include "input.h"

namespace sampson { namespace input {

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
		x = mx;
		y = my;
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

} }