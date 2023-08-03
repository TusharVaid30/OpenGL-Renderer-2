#pragma once

#include "Material.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GameObject
{
public:
	virtual void Draw() = 0;

	virtual void Translate(glm::vec3 newPosition) = 0;

	virtual void SetMaterial(Material* _mat) = 0;
};