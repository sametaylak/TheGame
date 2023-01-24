#pragma once

#include <glad/glad.h>

#include "shader.hpp"

struct program {
    GLuint Handle;
};

program* MakeProgram(shader* VertexShader, shader* FragmentShader);
void FreeProgram(program* Program);