#include "shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

shader* MakeShader(const char* ShaderFilePath, GLuint ShaderType)
{
    auto* Shader = (shader *)malloc(sizeof(shader));
    Shader->Handle = glCreateShader(ShaderType);

    std::ifstream ShaderFileStream(ShaderFilePath, std::ios::in);
    if (!ShaderFileStream.is_open()) {
        std::cout << "Failed to open shader file" << std::endl;
        exit(1);
    }

    std::stringstream  ShaderStringStream;
    ShaderStringStream << ShaderFileStream.rdbuf();
    std::string ShaderCode = ShaderStringStream.str();
    ShaderFileStream.close();

    char const* SourcePointer = ShaderCode.c_str();
    glShaderSource(Shader->Handle, 1, &SourcePointer, nullptr);
    glCompileShader(Shader->Handle);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    glGetShaderiv(Shader->Handle, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(Shader->Handle, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0){
        std::vector<char> ShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(Shader->Handle, InfoLogLength, nullptr, &ShaderErrorMessage[0]);
        std::cout << "Failed to compile shader: " << &ShaderErrorMessage[0] << std::endl;
        exit(1);
    }

    return Shader;
}

void FreeShader(shader* Shader)
{
    if (Shader) {
        free(Shader);
        Shader = nullptr;
    }
}