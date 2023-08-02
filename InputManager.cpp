#include "InputManager.h"

void InputManager::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}