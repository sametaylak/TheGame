#pragma once

#include "glad/glad.h"
#include <vector>

struct vertex_buffer {
    GLuint Handle;
    const std::vector<GLfloat>* Data;
};

vertex_buffer* MakeVertexBuffer(const std::vector<GLfloat>* Data);
void BindVertexBuffer(vertex_buffer* VertexBuffer);
void FreeVertexBuffer(vertex_buffer* VertexBuffer);