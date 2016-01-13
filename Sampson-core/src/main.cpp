#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexbuffer.h"
#include "graphics/buffers/vertexarray.h"

#include "input/input.h"

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>


int main()
{
	Window window("Sampson Engine v0.1a", 960, 540);
	Input input(&window);
	
	window.setBackgroundColor(glm::vec3(0.1f, 0.3f, 0.3f));

#if 0
	GLfloat vertices[]{
		0, 0, 0, 
		8, 0, 0, 
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};
	
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#else
	GLfloat vertices[] = {
		0, 0, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};
	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};
	GLfloat colorsA[] = {
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};
	GLfloat colorsB[] = {
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1
	};

	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);

	sprite1.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);

#endif

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);

	shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(), glm::vec3(4,3,0)));
	shader.setUniform4f("colour", glm::vec4(0.9f, 0.4f, 0.6f, 1.0f));

	while (!window.shouldClose())
	{

		if (input.isKeyPressed(GLFW_KEY_ESCAPE))
		{
			window.close();
		}


		window.clear();
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else
		sprite1.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(), glm::vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite1.unbind();

		sprite2.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(), glm::vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite2.unbind();
		
#endif

		window.update();
	}

	return 0;
}