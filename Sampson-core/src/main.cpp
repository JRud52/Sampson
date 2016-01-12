#include "graphics/window.h"
#include "input/input.h"
#include <GLM/vec2.hpp>
#include "graphics/sprite.h"
#include "utils/fileutils.h"
//#include "shaders/shader.h"


int main()
{
	Window window("Sampson Engine v0.1a", 960, 540);
	Input input(&window);
	
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLfloat speedV = 0.0f;
	GLfloat speedH = 0.0f;





	Sprite sprite1( glm::vec2(0.0f, 0.0f), (GLfloat)0.0f, (GLint)0);

	while (!window.shouldClose())
	{
		window.clear();
		
		if (input.isKeyPressed(GLFW_KEY_W)) 
		{
			 std::cout << "W key pressed!" << std::endl;
			 speedV = 0.01f;
		}
		if (input.isKeyPressed(GLFW_KEY_A))
		{
			std::cout << "A key pressed!" << std::endl;
			speedH = -0.01f;
		}
		if (input.isKeyPressed(GLFW_KEY_S))
		{
			std::cout << "S key pressed!" << std::endl;
			speedV = -0.01f;
		}
		if (input.isKeyPressed(GLFW_KEY_D))
		{
			std::cout << "D key pressed!" << std::endl;
			speedH = 0.01f;
		}
		if (input.isKeyPressed(GLFW_KEY_ESCAPE))
		{
			std::cout << "Esc key pressed!" << std::endl;
			window.close();
		}
		if (input.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "Left mouse button pressed!" << std::endl;
		if (input.isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
			std::cout << "Right mouse button pressed!" << std::endl;


		speedV *= window.deltaTime() * 100;
		speedH *= window.deltaTime() * 100;












		sprite1.Draw();
		

		speedV = 0.0f;
		speedH = 0.0f;

		window.update();
	}

	return 0;
}