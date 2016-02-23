#include "SampsonCoreHeaders.h"

int main()
{
	Window window("Sampson Engine v0.1a", 1600, 900);
	Input input(&window);
	
	window.setBackgroundColor(glm::vec3(0.1f, 0.3f, 0.3f));

	glm::mat4 ortho = glm::ortho(0.0f, 1600.0f, 0.0f, 900.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(), glm::vec3(4,3,0)));

	Renderable2D sprite(glm::vec3(500, 500, 0), glm::vec2(400, 400), glm::vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(glm::vec3(700, 100, 0), glm::vec2(200, 300), glm::vec4(0.2f, 0, 1, 1), shader);

	Simple2DRenderer renderer;

	shader.setUniform4f("colour", glm::vec4(0.9f, 0.4f, 0.6f, 1.0f));

	int speed = 200;

	while (!window.shouldClose())
	{

		if (input.isKeyPressed(GLFW_KEY_ESCAPE)) window.close();
		if (input.isKeyPressed(GLFW_KEY_A)) sprite.position = glm::vec3(sprite.position.x - speed * window.deltaTime(), sprite.position.y, sprite.position.z);   //sprite.setPosition(glm::vec3(0,0,0));
		if (input.isKeyPressed(GLFW_KEY_D)) sprite.position = glm::vec3(sprite.position.x + speed * window.deltaTime(), sprite.position.y, sprite.position.z);   //sprite.setPosition(glm::vec3(0,0,0));
		if (input.isKeyPressed(GLFW_KEY_W)) sprite.position = glm::vec3(sprite.position.x, sprite.position.y + speed * window.deltaTime(), sprite.position.z);   //sprite.setPosition(glm::vec3(0,0,0));
		if (input.isKeyPressed(GLFW_KEY_S)) sprite.position = glm::vec3(sprite.position.x, sprite.position.y - speed * window.deltaTime(), sprite.position.z);   //sprite.setPosition(glm::vec3(0,0,0));



		window.clear();

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}

	return 0;
}