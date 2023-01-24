#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

struct camera {
    glm::vec3 Position;
    glm::vec3 Direction;
    glm::vec3 UpVector;

    float Speed;
    float Sensitivity;
    float NearPlane;
    float FarPlane;

    float Yaw, Pitch;

    double LastMouseX, LastMouseY;
};

camera* MakeCamera(GLFWwindow* Window);
glm::mat4 GetCameraMatrix(camera* Camera);
void HandleCameraInputs(GLFWwindow* Window, camera* Camera, float DeltaTime);
void FreeCamera(camera* Camera);