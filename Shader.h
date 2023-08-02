#pragma once

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>

class Shader
{
private:
	GLuint shaderProgram;

public:
	Shader(const char* vertexPath, const char* fragmentPath);

	void Use();
	GLuint GetID();
};