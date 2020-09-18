#pragma once
#ifndef __TRIANGLE_H_
#define __TRIANGLE_H_

#include <glad\glad.h>
#include<glm/vec3.hpp>

#include<iostream>
#include"ShaderManager.h"


class Triangle
{
public:
	Triangle();
	~Triangle();

	void Initialized();
	void Update();
	void Draw(ShaderManager shader);
	void ShutDown();

private:
	unsigned int VBO, VAO, EBO;
	
	

};
#endif // !__TRIANGLE_H_