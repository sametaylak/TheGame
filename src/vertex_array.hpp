#pragma once

#include "glad/glad.h"

struct vertex_array {
    GLuint Handle;
};

vertex_array* MakeVertexArray();
void BindVertexArray(vertex_array* VertexArray);
void FreeVertexArray(vertex_array* VertexArray);