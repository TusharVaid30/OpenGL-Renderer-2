#include "Window.h"
#include "InputManager.h"
#include "Triangle.h"

#include <iostream>

void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

	std::cout << "WIDTH: " << width << ", HEIGHT: " << height << std::endl;
}

int main()
{
	Window windowHandler;
	GLFWwindow* window = windowHandler.createWindow(800, 600);

	InputManager inputManager;

	glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

	Triangle *tri = new Triangle();
	tri->Translate(glm::vec3(-0.5f, 0.0f, 0.0f));

	Triangle* tri2 = new Triangle();
	tri2->Translate(glm::vec3(0.5f, 0.0f, 0.0f));

	while (!glfwWindowShouldClose(window))
	{
		inputManager.ProcessInput(window);

		glClearColor(0.2f, 0.0f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		tri->Draw();
		tri2->Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}