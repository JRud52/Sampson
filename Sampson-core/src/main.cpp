#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexbuffer.h"
#include "graphics/buffers/vertexarray.h"

#include "input/input.h"

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include "graphics/simple2drenderer.h"
#include "graphics/renderable2d.h"

int main()
{
	Window window("Sampson Engine v0.1a", 960, 540);
	Input input(&window);
	
	window.setBackgroundColor(glm::vec3(0.1f, 0.3f, 0.3f));

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(), glm::vec3(4,3,0)));

	Renderable2D sprite(glm::vec3(5, 5, 0), glm::vec2(4, 4), glm::vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(glm::vec3(7, 1, 0), glm::vec2(2, 3), glm::vec4(0.2f, 0, 1, 1), shader);

	Simple2DRenderer renderer;

	shader.setUniform4f("colour", glm::vec4(0.9f, 0.4f, 0.6f, 1.0f));

	while (!window.shouldClose())
	{

		if (input.isKeyPressed(GLFW_KEY_ESCAPE))
		{
			window.close();
		}

		window.clear();

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}

	return 0;
}