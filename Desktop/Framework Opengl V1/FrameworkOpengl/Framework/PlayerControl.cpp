#include "PlayerControl.h"
#include"InputManager.h"
#include"Game.h"


PlayerControl::PlayerControl(): m_pCamera(nullptr)
{

}

PlayerControl::~PlayerControl()
{

}

void PlayerControl::Initialized(GLFWwindow* window)
{
	m_pCamera = new Camera();

  

}

void PlayerControl::Update(float deltaTime)
{
	glm::vec3 cameraPosition = m_pCamera->GetPosition();

    float speed = 1.0f;


    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_W))
    {
        cameraPosition.z += speed * deltaTime;
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_S))
    {
        cameraPosition.z -= speed * deltaTime;
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_A))
    {
        cameraPosition.x += speed * deltaTime;
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_D))
    {
        cameraPosition.x -= speed * deltaTime;
    }

    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_SPACE))
    {
        cameraPosition.y -= speed * deltaTime;
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_Z))
    {
        cameraPosition.y += speed * deltaTime;
    }
   

   

	m_pCamera->SetPosition(cameraPosition);

}

glm::vec3 PlayerControl::GetCameraPosition()
{
	return m_pCamera->GetPosition();
}

glm::mat4 PlayerControl::GetCameraView()
{
	return m_pCamera->GetViewMatrix();
}
