#include "Triangle.h"

Triangle::Triangle()
{
	shader = new Shader("vertex.shader", "fragment.shader");

	Texture* tex = new Texture();

	float vertices[] =
	{
		0.5f,  0.5f, 0.0f,		1.0f, 1.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
	   -0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
	   -0.5f,  0.5f, 0.0f,		0.0f, 1.0f,
		0.5f,  0.5f, 0.0f,		1.0f, 1.0f,
	   -0.5f, -0.5f, 0.0f,		0.0f, 0.0f
	};

	glGenVertexArrays(1, &VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Triangle::Draw()
{
	shader->Use();
	glBindVertexArray(VAO);
	GLuint transformLoc = glGetUniformLocation(shader->GetID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(position));
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Triangle::Translate(glm::vec3 newPosition)
{
	position = glm::translate(position, newPosition);
}