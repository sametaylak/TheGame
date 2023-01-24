#pragma once

#include <glad/glad.h>

struct shader {
    GLuint Handle;
};

shader* MakeShader(const char* ShaderSource, GLuint ShaderType);
void FreeShader(shader* Shader);