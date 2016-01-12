#version 330 core

out vec4 color;

uniform vec3 diffuse;

void main()
{
    color = vec4(diffuse, 1.0f);
}