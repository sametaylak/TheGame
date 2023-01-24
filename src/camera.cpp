#include "camera.hpp"

#include <iostream>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

camera* MakeCamera(GLFWwindow* Window)
{
    auto* Camera = (camera *)malloc(sizeof(camera));
    Camera->Position = glm::vec3(0.0f, 0.0f, 5.0f);
    Camera->Direction = glm::vec3(0.0f, 0.0f, -1.0f);
    Camera->UpVector = glm::vec3(0.0f, 1.0f, 0.0f);
    Camera->NearPlane = 0.1f;
    Camera->FarPlane = 100.0f;
    Camera->Speed = 6.0f;
    Camera->Sensitivity = 5.0f;
    Camera->Yaw = -90.0f;
    Camera->Pitch = 0.0f;

    // Set initial cursor position as last mouse position
    glfwGetCursorPos(Window, &Camera->LastMouseX, &Camera->LastMouseY);

    return Camera;
}


glm::mat4 GetCameraMatrix(camera* Camera)
{
    auto ViewMatrix = glm::lookAt(Camera->Position, Camera->Position + Camera->Direction, Camera->UpVector);
    auto ProjectionMatrix = glm::perspective(glm::radians(45.0f), 1080.0f / 720.0f, Camera->NearPlane, Camera->FarPlane);

    return ProjectionMatrix * ViewMatrix;
}

void HandleCameraInputs(GLFWwindow* Window, camera* Camera, float DeltaTime)
{
    if (glfwGetKey(Window, GLFW_KEY_W) == GLFW_PRESS)
    {
        Camera->Position += DeltaTime * Camera->Speed * Camera->Direction;
    }

    if (glfwGetKey(Window, GLFW_KEY_A) == GLFW_PRESS)
    {
        Camera->Position += DeltaTime * Camera->Speed * -glm::normalize(glm::cross(Camera->Direction, Camera->UpVector));
    }

    if (glfwGetKey(Window, GLFW_KEY_S) == GLFW_PRESS)
    {
        Camera->Position += DeltaTime * Camera->Speed * -Camera->Direction;
    }

    if (glfwGetKey(Window, GLFW_KEY_D) == GLFW_PRESS)
    {
        Camera->Position += DeltaTime * Camera->Speed * glm::normalize(glm::cross(Camera->Direction, Camera->UpVector));
    }

    double MouseX, MouseY;
    glfwGetCursorPos(Window, &MouseX, &MouseY);

    auto OffsetX = (float)(MouseX - Camera->LastMouseX) * DeltaTime * Camera->Sensitivity;
    auto OffsetY = (float)(Camera->LastMouseY - MouseY) * DeltaTime * Camera->Sensitivity;

    Camera->Yaw += OffsetX;
    Camera->Pitch += OffsetY;

    glm::vec3 Direction = glm::vec3(
        cos(glm::radians(Camera->Yaw)) * cos(glm::radians(Camera->Pitch)),
        sin(glm::radians(Camera->Pitch)),
        sin(glm::radians(Camera->Yaw)) * cos(glm::radians(Camera->Pitch))
    );

    // Get unit vector of direction
    Camera->Direction = glm::normalize(Direction);

    glfwSetCursorPos(Window, 1080.0f / 2.0f, 720.0f / 2.0f);
    glfwGetCursorPos(Window, &MouseX, &MouseY);
    Camera->LastMouseX = MouseX;
    Camera->LastMouseY = MouseY;
}

void FreeCamera(camera* Camera)
{
    if (Camera) {
        free(Camera);
        Camera = nullptr;
    }
}