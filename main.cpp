#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>

#define TITLE_UPDATE_TIME 0.5

void update(double delta)
{
	
} 

int main()
{
	glfwInit();
	glewExperimental = GL_TRUE; 
	glewInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	GLFWwindow * window = glfwCreateWindow(800,600, "OpenGL", nullptr, nullptr);

	glfwMakeContextCurrent(window);
	
	auto lastTime = std::chrono::system_clock::now();
	double secondsSinceTitleUpdate = 0.0;  
	
	while(!glfwWindowShouldClose(window))
	{	
		auto currentTime = std::chrono::system_clock::now();
		std::chrono::duration<float, std::milli> elapsed_time = currentTime-lastTime ;
		float delta = elapsed_time.count() / 1000.0;
	  
		lastTime = currentTime;
		
		secondsSinceTitleUpdate += delta;
		if (secondsSinceTitleUpdate >=  TITLE_UPDATE_TIME)
		{
			float fps = 1.f / delta; 
			
			char buffer[20]; 
			sprintf(buffer, "OpenGL FPS: %f", fps);
			glfwSetWindowTitle(window, buffer);
			secondsSinceTitleUpdate = 0.0;
		}

		update(delta);
			
		glfwSwapBuffers(window);
		glfwPollEvents();
		
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{      
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	}		
	
	glfwTerminate();
	return 0;
}