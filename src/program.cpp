#include "program.hpp"

#include <iostream>
#include <cstdlib>
#include <vector>

program* MakeProgram(shader* VertexShader, shader* FragmentShader)
{
    program* Program = (program *)malloc(sizeof(program));
    Program->Handle = glCreateProgram();

    glAttachShader(Program->Handle, VertexShader->Handle);
    glAttachShader(Program->Handle, FragmentShader->Handle);
    glLinkProgram(Program->Handle);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    glGetProgramiv(Program->Handle, GL_LINK_STATUS, &Result);
    glGetProgramiv(Program->Handle, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(Program->Handle, InfoLogLength, nullptr, &ProgramErrorMessage[0]);
        std::cout << "Failed to compile vertex shader: " << &ProgramErrorMessage[0] << std::endl;
        exit(1);
    }

    glDetachShader(Program->Handle, VertexShader->Handle);
    glDetachShader(Program->Handle, FragmentShader->Handle);

    glDeleteShader(VertexShader->Handle);
    glDeleteShader(FragmentShader->Handle);

    return Program;
}

void FreeProgram(program* Program)
{
    if (Program) {
        free(Program);
        Program = nullptr;
    }
}
