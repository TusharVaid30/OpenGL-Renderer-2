#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Texture.h"
#include "GameObject.h"
#include "Material.h"

class Triangle : public GameObject
{
private:
	GLuint VAO;
	Shader *shader;
	Texture* texture;
	Material* mat;

	glm::mat4 model = glm::mat4(1.0f);

public:
	Triangle();

	void SetMaterial(Material* _mat);
	void Draw();
	void Translate(glm::vec3 newPosition);
};