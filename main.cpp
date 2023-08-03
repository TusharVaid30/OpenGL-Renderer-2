#include "Window.h"
#include "InputManager.h"
#include "Triangle.h"
#include "GameObject.h"
#include "Material.h"
#include "Camera.h"

#include <iostream>
#include <iterator>
#include <list>

void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

	std::cout << "WIDTH: " << width << ", HEIGHT: " << height << std::endl;
}

float x = -0.5f;

Shader *defaultLitShader;
Texture* texture;

bool pressed = false;

void compileAllShaders()
{
	defaultLitShader = new Shader("vertex.shader", "fragment.shader");
}

void generateTextures()
{
	texture = new Texture();
}

int main()
{
	std::list<GameObject*> gameObjects;

	Window windowHandler;
	GLFWwindow* window = windowHandler.createWindow(800, 600);

	compileAllShaders();
	generateTextures();

	Camera cam;

	InputManager inputManager;

	Triangle *tri = nullptr;
	Material *mat = new Material();
	mat->SetShader(defaultLitShader);
	mat->SetTexture(texture);

	glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		inputManager.ProcessInput(window);

		glClearColor(0.2f, 0.0f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		cam.AttachShader(defaultLitShader);

		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && !pressed)
		{
			tri = new Triangle();
			tri->SetMaterial(mat);
			tri->Translate(glm::vec3(x, 0.0f, 1.0f));
			gameObjects.push_back(tri);
			x += 0.1f;

			pressed = true;
		}
		else if (glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS && !pressed)
		{
			if (!gameObjects.empty())
			{
				gameObjects.pop_back();
				pressed = true;
				x -= 0.1f;
			}
		}
		else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_RELEASE)
			pressed = false;

		for (GameObject* gameObject : gameObjects)
			gameObject->Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}