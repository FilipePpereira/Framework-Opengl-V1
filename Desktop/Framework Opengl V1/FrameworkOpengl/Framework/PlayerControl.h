#pragma once
#ifndef __PLAYERCONTROL_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include"Camera.h"


class PlayerControl
{
public:
	PlayerControl();
	~PlayerControl();

	void Initialized(GLFWwindow* window);
	void Update(float deltaTime);

	glm::vec3 GetCameraPosition();
	glm::mat4 GetCameraView();

private:

	Camera* m_pCamera;

};

#endif // !__PLAYERCONTROL_H_


