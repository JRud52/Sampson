#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"
#include "shader.h"
#include <GLM/glm.hpp>

class Renderable2D
{
public:
	glm::vec3 position;
	glm::vec2 scale;
	glm::vec4 color;

protected:
	VertexArray* m_VertexArray;
	IndexBuffer* m_IndexBuffer;
	Shader& m_Shader;

public:
	//initialize the renderable2d
	Renderable2D(glm::vec3 position, glm::vec2 scale, glm::vec4 color, Shader& shader)
		: position(position), scale(scale), color(color), m_Shader(shader)
	{
		m_VertexArray = new VertexArray();
		GLfloat vertices[] = {
			0, 0, 0,
			0, scale.y, 0,
			scale.x, scale.y, 0,
			scale.x, 0, 0
		};

		GLfloat colors[] = {
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w
		};

		m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
		m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

		GLushort indices[]{ 0, 1, 2, 2, 3, 0};
		m_IndexBuffer = new IndexBuffer(indices, 6);
	};

	//free up memory
	~Renderable2D()
	{
		delete m_VertexArray;
		delete m_IndexBuffer;
	}

	inline const VertexArray* getVAO() const { return m_VertexArray; }
	inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }

	inline Shader& getShader() const { return m_Shader; }

	inline const glm::vec3& getPosition() const { return position; }
	inline const glm::vec2& getScale() const { return scale; }
	inline const glm::vec4& getColor() const { return color; }

	// const void setPosition(glm::vec3 position) { this->position = position; }
};