#include "src/graphics/window.h"
#include "src\math\vec2.h"

int main()
{
	using namespace sampson;
	using namespace graphics;
	using namespace math;

	Window window("Sampson v0.1a", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 a(1.0f, 2.0f);
	vec2 b(2.0f, 1.0f);

	std::cout << a << std::endl;

	while (!window.closed())
	{
		window.clear();
		
		

#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		
		window.update();
	}

	return 0;
}