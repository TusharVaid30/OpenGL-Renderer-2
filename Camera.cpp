#include "Camera.h"

void Camera::AttachShader(Shader* _shader)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::translate(view, position);
	view = glm::rotate(view, glm::radians(rotationAngle), axis);
	projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);

	int viewLoc = glGetUniformLocation(_shader->GetID(), "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	int projectionLoc = glGetUniformLocation(_shader->GetID(), "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Camera::SetPosition(glm::vec3 _position)
{
	position = _position;
}

void Camera::SetRotation(float _rotationAngle, glm::vec3 _axis)
{
	rotationAngle = _rotationAngle;
	axis = _axis;
}

void Camera::SetFOV(float _fov)
{
	fov = _fov;
}