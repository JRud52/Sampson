#pragma once

#include <GL/glew.h>
#include <GLM/vec2.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include "../shaders/shader.h"
#include <SOIL/SOIL.h>


class Sprite {
private:
	bool m_isTextured;
	Shader* m_Shader;
	GLuint VBO, VAO, EBO, VAO2;
	GLuint texture;

public:
	
	struct transform {
		glm::vec2 translation; GLfloat rotation; GLint zIndex;
	};
	transform transform;
	

public:
	Sprite();
	Sprite(glm::vec2 position, GLfloat rotation, GLint zIndex);
	~Sprite();
	void Init();
	void Draw();

};

