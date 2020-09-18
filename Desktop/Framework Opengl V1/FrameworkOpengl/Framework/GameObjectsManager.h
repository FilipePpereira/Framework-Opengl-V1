#pragma once
#ifndef __GAME_OBJECTS_MANAGER_H_
#define __GAME_OBJECTS_MANAGER_H_


#include"Triangle.h"
#include"CubeObject.h"

class GameObjectsManager
{
public:
	GameObjectsManager();
	~GameObjectsManager();


	void Initialized();
	void Update();
	void Render(ShaderManager shader);
	void ShutDown();

	Triangle* GetTriangle();
	CubeObject* GetCubeObject();

private:
	Triangle* m_triangle;
	CubeObject* m_cubeObject;


};
#endif // !__GAME_OBJECTS_MANAGER_H_

