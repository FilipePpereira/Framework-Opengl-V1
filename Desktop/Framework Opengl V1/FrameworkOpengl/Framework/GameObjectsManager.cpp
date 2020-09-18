#include "GameObjectsManager.h"

GameObjectsManager::GameObjectsManager()
{
	m_triangle = new Triangle();
	m_cubeObject = new CubeObject();
}

GameObjectsManager::~GameObjectsManager()
{
}

void GameObjectsManager::Initialized()
{
	
	m_triangle->Initialized();
	m_cubeObject->Initialized();
}

void GameObjectsManager::Update()
{
	/*m_triangle->Update();*/
}

void GameObjectsManager::Render(ShaderManager shader)
{
	m_triangle->Draw(shader);
	m_cubeObject->Draw(shader);
}

void GameObjectsManager::ShutDown()
{
	m_triangle->ShutDown();
	m_cubeObject->Shutdown();
}

Triangle* GameObjectsManager::GetTriangle()
{
	return m_triangle;
}

CubeObject* GameObjectsManager::GetCubeObject()
{
	return m_cubeObject;
}
