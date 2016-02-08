#include "vertexarray.h"

//initialize the vertex array
VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_ArrayID);
}

//destroy the vertex array
VertexArray::~VertexArray()
{
	for (int i = 0; i < m_Buffers.size(); i++)
		delete m_Buffers[i];
}

//add buffer to the vertex array
void VertexArray::addBuffer(Buffer* buffer, GLuint index) 
{
	bind();
	buffer->bind();

	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

	buffer->unbind();
	unbind();
}

//bind the vertex array
void VertexArray::bind() const
{
	glBindVertexArray(m_ArrayID);
}

//unbind the vertex array
void VertexArray::unbind() const
{
	glBindVertexArray(m_ArrayID);
}