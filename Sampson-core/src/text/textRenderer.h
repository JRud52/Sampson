#pragma once
#include <iostream>
#include <map>
#include <GL\glew.h>
#include <GLM\glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H


class TextRenderer {
	struct Character 
	{
		GLuint TextureID;
		glm::ivec2 Size;
		glm::ivec2 Bearing;
		GLuint Advance;
	};

	std::map<GLchar, Character> Characters;

public:
	FT_Library library;
	FT_Face face;

	TextRenderer() {
		if (FT_Init_FreeType(&library)) std::cout << "FreeType could not be initialized." << std::endl;
		if (FT_New_Face(library, "fonts/arial.ttf", 0, &face)) std::cout << "Failed to load font" << std::endl;
		FT_Set_Pixel_Sizes(face, 0, 48);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		for (GLubyte c = 0; c < 128; c++) 
		{
			//Load the character glyph
			if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			{
				std::cout << "Failed to load glyph." << std::endl;
				continue;
			}
			// Generate texture
			GLuint texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0,
				GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
			//Set texture options
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			// store the character for later use
			Character character = { texture, glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
				glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top), face->glyph->advance.x
			};
			Characters.insert(std::pair<GLchar, Character>(c, character));
		}

		FT_Done_Face(face);
		FT_Done_FreeType(library);

	}



};

