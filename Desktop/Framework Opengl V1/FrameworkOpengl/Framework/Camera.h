#pragma once
#ifndef __CAMERA_H_
#define __CAMERA_H_


#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>



class Camera
{
public:
	Camera();
	~Camera();

	void SetPosition(float x, float y, float z);
	void SetPosition(glm::vec3 position);
	

	// getters
	glm::vec3 GetPosition();

	glm::vec3 GetCameraUp();
	
	glm::vec3 GetCameraRight();

	glm::vec3 GetCameraFront();

	glm::vec3 GetRotation();

	glm::mat4 GetViewMatrix();

private:
	void UpdateCameraVectors();


private:

	glm::vec3 m_CameraPosition;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;
	glm::vec3 cameraFront;
	glm::vec3 cameraRotation;
	glm::vec3 worldUp;

	glm::mat4 view;

	float yaw;    // cos x / h = cos x / 1 = cos x
	float pitch; // sin y / h = sin y / 1 = sin y.
	float speed;
	float sensitivity;
	float zoom;

};
#endif // !__CAMERA_H_

