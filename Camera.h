#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

class Camera
{
private:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, -3.0f);
	float rotationAngle = 0.0f;
	glm::vec3 axis = glm::vec3(0.0f, 0.0f, 1.0f);
	float fov = 45.0f;

public:
	void SetPosition(glm::vec3 _position);
	void SetRotation(float _rotationAngle, glm::vec3 _axis);

	void SetFOV(float _fov);

	void AttachShader(Shader* _shader);
};