#include "Camera.h"

Camera::Camera(): m_CameraPosition(glm::vec3(0.0f, 0.0f, 3.0f)),
                  cameraUp(glm::vec3(0.0f, 1.0f, 0.0f)),
                  worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
                  cameraRight(glm::vec3(0.0f, 0.0f, 0.0f)),
                  cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
                  cameraRotation(glm::vec3(0.0f, 0.0f, 0.0f)),
                  yaw(-90.0f), pitch(0.0f), speed(1.0f), sensitivity(1.0f), zoom(45.0f)





{
    view = glm::lookAt(m_CameraPosition, m_CameraPosition + cameraFront, cameraUp);
    UpdateCameraVectors();
}

Camera::~Camera()
{
}

void Camera::UpdateCameraVectors()
{
    glm::vec3 direction;

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    cameraFront = glm::normalize(direction);
    cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
    cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
}

void Camera::SetPosition(float x, float y, float z)
{
    m_CameraPosition.x = x;
    m_CameraPosition.y = y;
    m_CameraPosition.z = z;
}

void Camera::SetPosition(glm::vec3 position)
{
    m_CameraPosition = position;
}

glm::vec3 Camera::GetPosition()
{
    return m_CameraPosition;
}

glm::vec3 Camera::GetCameraUp()
{
    return cameraUp;
}

glm::vec3 Camera::GetCameraRight()
{
    return cameraRight;
}

glm::vec3 Camera::GetCameraFront()
{
    return cameraFront;
}

glm::vec3 Camera::GetRotation()
{
    return cameraRotation;
}

glm::mat4 Camera::GetViewMatrix()
{
    return view;
}
