#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Texture.h"

class Triangle
{
private:
	GLuint VAO;
	Shader *shader;

	glm::mat4 position = glm::mat4(1.0f);

public:
	Triangle();

	void Draw();
	void Translate(glm::vec3 newPosition);
};