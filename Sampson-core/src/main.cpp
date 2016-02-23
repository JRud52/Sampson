#include "SampsonCoreHeaders.h"

#define WIN_WIDTH 1600
#define WIN_HEIGHT 900

int main()
{
	Window window("Sampson Engine v0.1a", WIN_WIDTH, WIN_HEIGHT);
	Input input(&window);
	
	window.setBackgroundColor(glm::vec3(0.1f, 0.3f, 0.3f));

	glm::mat4 ortho = glm::ortho(0.0f, (float)WIN_WIDTH, 0.0f, (float)WIN_HEIGHT);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(), glm::vec3(4,3,0)));

	Renderable2D sprite(glm::vec3(500, 500, 0), glm::vec2(400, 400), glm::vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(glm::vec3(700, 100, 0), glm::vec2(200, 300), glm::vec4(0.2f, 0, 1, 1), shader);

	Simple2DRenderer renderer;

	shader.setUniform4f("colour", glm::vec4(0.9f, 0.4f, 0.6f, 1.0f));

	int speed = 200;

	Stats stats;
	while (!window.shouldClose())
	{
		 stats.printFPS();

		if (input.isKeyPressed(GLFW_KEY_ESCAPE)) window.close();
		if (input.isKeyPressed(GLFW_KEY_A)) sprite.setPosition(glm::vec3(sprite.getPosition().x - speed * window.deltaTime(), sprite.getPosition().y, sprite.getPosition().z));
		if (input.isKeyPressed(GLFW_KEY_D)) sprite.setPosition(glm::vec3(sprite.getPosition().x + speed * window.deltaTime(), sprite.getPosition().y, sprite.getPosition().z));
		if (input.isKeyPressed(GLFW_KEY_W)) sprite.setPosition(glm::vec3(sprite.getPosition().x, sprite.getPosition().y + speed * window.deltaTime(), sprite.getPosition().z));
		if (input.isKeyPressed(GLFW_KEY_S)) sprite.setPosition(glm::vec3(sprite.getPosition().x, sprite.getPosition().y - speed * window.deltaTime(), sprite.getPosition().z));

		window.clear();

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}

	return 0;
}