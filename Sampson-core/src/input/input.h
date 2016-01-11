#pragma once

#include "../graphics/window.h"

namespace sampson { namespace input {

#define MAX_KEYS		1024
#define MAX_BUTTONS		32

	class Input 
	{
	private:
		static bool m_Keys[MAX_KEYS];
		static bool m_MouseButtons[MAX_BUTTONS];
		static double m_mouseX, m_mouseY;
		//graphics::Window* windowInstance;

	public:
		Input(graphics::Window* window);
		~Input();

		bool isKeyPressed(unsigned int keycode) const;
		bool isMouseButtonPressed(unsigned int button) const;
		void getMousePosition(double& x, double& y) const;

	private:
		bool Init();
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	};

} }