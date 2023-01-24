cmake_minimum_required(VERSION 3.24)
project(TheGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/glm)

add_executable(TheGame
    src/main.cpp
    src/shader.hpp
    src/shader.cpp
    src/vertex_buffer.hpp
    src/vertex_buffer.cpp
    src/vertex_array.hpp
    src/vertex_array.cpp
    src/program.cpp
    src/program.hpp
    src/camera.hpp
    src/camera.cpp
)
target_link_libraries(TheGame PRIVATE glfw glad glm)
