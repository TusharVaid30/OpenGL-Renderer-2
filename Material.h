#pragma once

#include "Texture.h"
#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Material
{
private:
	glm::vec3 color;

public:
	Material();
	Shader* shader;
	Texture* tex;

	void SetColor(glm::vec3 _color);
	void SetTexture(Texture* _tex);
	void SetShader(Shader* _shader);
};