#include "ShaderManager.h"

ShaderManager::ShaderManager(): m_pshader(nullptr)
{
}

ShaderManager::~ShaderManager()
{
}



void ShaderManager::InitializedShaderManager(const char* vertexShaderPath, const char* fragShaderPath)
{
	m_pshader = new Shader();
	m_pshader->InitShaders(vertexShaderPath, fragShaderPath);
}

void ShaderManager::UpdateShaderManager()
{
	m_pshader->activate();
}

void ShaderManager::ShutDownShaderManager()
{
	
}

Shader* ShaderManager::GetShader()
{
	return m_pshader;
}
