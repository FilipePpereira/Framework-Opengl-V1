#pragma once
#ifndef __SHADER_MANAGER_H_
#define __SHADER_MANAGER_H_

#include"Shader.h"



class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

	void InitializedShaderManager(const char* vertexShaderPath, const char* fragShaderPath);
	void UpdateShaderManager();
	void ShutDownShaderManager();
	
	Shader* GetShader();

private:
	Shader* m_pshader;

};
#endif // !__SHADER_MANAGER_H_
