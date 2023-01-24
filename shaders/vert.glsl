#version 410 core
layout (location = 0) in vec3 aPos;
layout(location = 1) in vec3 vertexColor;

out vec3 fragmentColor;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * vec4(aPos, 1.0);
    fragmentColor = vertexColor;
}