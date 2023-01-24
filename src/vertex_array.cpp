#include "vertex_array.hpp"
#include <cstdlib>

vertex_array* MakeVertexArray()
{
    vertex_array* VertexArray = (vertex_array *)malloc(sizeof(vertex_array));

    glGenVertexArrays(1, &VertexArray->Handle);
    
    return VertexArray;
}

void BindVertexArray(vertex_array* VertexArray)
{
    glBindVertexArray(VertexArray->Handle);
}

void FreeVertexArray(vertex_array* VertexArray)
{
    if (VertexArray) {
        glDeleteVertexArrays(1, &VertexArray->Handle);

        free(VertexArray);
        VertexArray = nullptr;
    }
}