#include "vertex_buffer.hpp"
#include <cstdlib>
#include <vector>

vertex_buffer* MakeVertexBuffer(const std::vector<GLfloat>* Data)
{
    vertex_buffer* VertexBuffer = (vertex_buffer *)malloc(sizeof(vertex_buffer));
    VertexBuffer->Data = Data;

    glGenBuffers(1, &VertexBuffer->Handle);

    glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer->Handle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * VertexBuffer->Data->size(), VertexBuffer->Data->data(), GL_STATIC_DRAW);
    
    return VertexBuffer;
}

void BindVertexBuffer(vertex_buffer* VertexBuffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer->Handle);
}

void FreeVertexBuffer(vertex_buffer* VertexBuffer)
{
    if (VertexBuffer) {
        glDeleteBuffers(1, &VertexBuffer->Handle);

        free(VertexBuffer);
        VertexBuffer = nullptr;
    }
}