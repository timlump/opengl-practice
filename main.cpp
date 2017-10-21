#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>

int main()
{
	glfwInit();
	glewExperimental = GL_TRUE;
	glewInit();
	
	std::cout << "Hello World!";
	glfwTerminate();
	return 0;
}