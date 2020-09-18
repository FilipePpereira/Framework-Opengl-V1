#pragma once
#ifndef __GAME_H_
#define __GAME_H_

// core window
#include<Windows.h>
#include<iostream>
#include<string>

// include glad 
#include <glad\glad.h>

// include glfw 
#include<GLFW/glfw3.h>
#include<GLFW/glfw3native.h>



#include"GameObjectsManager.h"
#include"ShaderManager.h"
#include"PlayerControl.h"


class Game
{
public:

	static Game* Instance()
	{
		if (s_pGame == nullptr)
		{
			s_pGame = new Game();
			return s_pGame;
		}
		return s_pGame;
	}

	Game();
	~Game();

	bool Initialized(std::string title, int with, int height);
	void Run();
	void Update();
	void Draw();
	void Shutdown();
	GLFWwindow* GetWindow() { return m_pWindow; };

private:

	void InitShaders();
	void CreateGameObjects();

	GLFWwindow* m_pWindow;

	int m_screenWidth;
	int m_screenHeight;

	float lastTime;
	float currentTime;
	float deltaTime;


	// Game Objects
	GameObjectsManager* m_triangle;
	GameObjectsManager* m_CubeObject;
	


	// shaders Manager
	ShaderManager* m_pShaderTriangle;
	ShaderManager* m_pShaderCube;


	// Player Control
	PlayerControl* m_pPlayerControl;

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static Game* s_pGame;
};
#endif // !__GAME_H_


