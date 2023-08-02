#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window();

	GLFWwindow* createWindow(int x, int y);
};