#include "graphics/window.h"
#include "input/input.h"
#include "math/vec2.h"
#include "shaders/shader.h"


int main()
{
	using namespace sampson;
	using namespace graphics;
	using namespace math;
	using namespace input;

	Window window("Sampson v0.1a", 960, 540);
	Input input(&window);
	
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLfloat speedV = 0.0f;
	GLfloat speedH = 0.0f;
	GLfloat positionPos = 0.5f;
	GLfloat positionNeg = -0.5f;

	vec2 topLeft(-0.5f, -0.5f);
	vec2 topRight(-0.5f, 0.5f);
	vec2 bottomRight(0.5f, 0.5f);
	vec2 bottomLeft(0.5f, -0.5f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

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

		topLeft.x += speedH;
		topRight.x += speedH;
		bottomRight.x += speedH;
		bottomLeft.x += speedH;

		topLeft.y += speedV;
		topRight.y += speedV;
		bottomRight.y += speedV;
		bottomLeft.y += speedV;

#if 1
		glBegin(GL_QUADS);
		glVertex2f(topLeft.x, topLeft.y);
		glVertex2f(topRight.x, topRight.y);
		glVertex2f(bottomRight.x, bottomRight.y);
		glVertex2f(bottomLeft.x, bottomLeft.y);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		

		speedV = 0.0f;
		speedH = 0.0f;

		window.update();
	}

	return 0;
}