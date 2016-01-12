#include "graphics/window.h"
#include "input/input.h"
#include <GLM/vec2.hpp>
#include "graphics/sprite.h"
//#include "shaders/shader.h"


int main()
{

	Window window("Sampson Engine v0.1a", 960, 540);
	Input input(&window);
	
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLfloat speedV = 0.0f;
	GLfloat speedH = 0.0f;





	

	// Set up vertex data (and buffer(s)) and attribute pointers
	//GLfloat vertices[] = {
		// Positions         // Colors
	//	0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  // Bottom Right
	//	-0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  // Bottom Left
	//	0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f   // Top 
	//};
	//GLuint VBO, VAO;
	//glGenVertexArrays(1, &VAO);
	//glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	//glBindVertexArray(VAO);

	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Position attribute
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	//glEnableVertexAttribArray(0);
	// Color attribute
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	//glEnableVertexAttribArray(1);

	//glBindVertexArray(0); // Unbind VAO







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





		//m_Shader->Use();

		//glUseProgram(shaderProgram);
		////glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		//glBindVertexArray(0);









		sprite1.Draw();
		

		speedV = 0.0f;
		speedH = 0.0f;

		window.update();
	}

	return 0;
}