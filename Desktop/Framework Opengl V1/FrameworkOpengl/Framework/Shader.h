#pragma once
#ifndef __SHADER_H_
#define __SHADER_H_

#include<glad/glad.h>

// core
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// include glm
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>



class Shader
{
public:
	
	
	
	Shader();
	~Shader();

	// initialize with paths to vertex and fragment shaders
	void InitShaders(const char* vertexShaderPath, const char* fragShaderPath);

	// activate shader
	void activate();


	// set uniform variables

	void SetBool(const std::string& name, bool value) const;

	void SetInt(const std::string& name, int value) const;

	void SetFloat(const std::string& name, float value) const;

	void SetFloat4f(const std::string& name, float v1, float v2, float v3, float v4) const;

	void setVec2(const std::string& name, const glm::vec2& value) const;

	void setVec2(const std::string& name, float x, float y) const;

	void setVec3(const std::string& name, const glm::vec3& value) const;

	void setVec3(const std::string& name, float x, float y, float z) const;

	void setVec4(const std::string& name, const glm::vec4& value) const;

	void setMat2(const std::string& name, const glm::mat2& mat) const;

	void setMat3(const std::string& name, const glm::mat3& mat) const;

	void setVec4(const std::string& name, float x, float y, float z, float w);

	void SetMat4(const std::string& name, glm::mat4 value) const;





private:
	

	// program ID
	unsigned int shaderProgram;

	// generate using vertex and frag shaders
	void CompilerShaders(const char* vertexShaderPath, const char* fragShaderPath);

	// load string from file
	std::string loadShaderSrc(const char* filePath);

	// compile shader program
	GLuint compileShader(const char* filePath, GLuint type);


};

#endif // !__SHADER_H_
