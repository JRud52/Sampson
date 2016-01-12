#include "sprite.h"



Sprite::Sprite()
{
	transform.translation = glm::vec2(0.0f, 0.0f);
	transform.rotation = 0.0f;
	transform.zIndex = 0;
	Init();

}

Sprite::Sprite(glm::vec2 translation, GLfloat rotation = 0.0f, GLint zIndex = 0)
{
	transform.translation = translation;
	transform.rotation = rotation;
	transform.zIndex = zIndex;
	Init();
}

Sprite::~Sprite() 
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Sprite::Init()
{

	m_Shader = &Shader((GLchar*)"D:/Justin/Documents/Visual Studio 2015/Projects/Sampson/Sampson-core/src/shaders/shaders_default/default_textured.vert",
		(GLchar*)"D:/Justin/Documents/Visual Studio 2015/Projects/Sampson/Sampson-core/src/shaders/shaders_default/default_textured.frag");

	GLfloat vertices[] = {
		// Positions          // Texture Coords
		 0.5f,  0.5f, 0.0f,    1.0f, 1.0f,   // Top Right
		 0.5f, -0.5f, 0.0f,    1.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,    0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,    0.0f, 1.0f    // Top Left 
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3,  // First Triangle
		1, 2, 3   // Second Triangle
	};
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	VAO2 = VAO;

	// Load and create a texture 

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
										   // Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load image, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("D:/Justin/Documents/Visual Studio 2015/Projects/Sampson/Sampson-core/src/textures/awesomeface.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}

void Sprite::Draw()
{
	//GLint colorLoc = glGetUniformLocation(m_Shader->Program, "color_diffuse");
	//glUniform4fv(colorLoc, 1, value_ptr(vec4(0, 0, 0, 1.0f)));
	// Bind Texture
	glBindTexture(GL_TEXTURE_2D, texture);

	m_Shader->Use();
	VAO = VAO2;
	
	// Draw sprite
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}

