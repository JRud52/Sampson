#pragma once

#include <deque>
#include <GL/glew.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include "renderer2d.h"

class Simple2DRenderer : public Renderer2D
{
private:
	std::deque<const Renderable2D*> m_RenderQueue;

public:
	void submit(const Renderable2D* renderable) override;
	void flush() override;
};