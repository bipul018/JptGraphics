#pragma once


#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Array.h"

struct JptWindow {
	GLFWwindow* window;
	int width;
	int height;
};
typedef struct JptWindow JptWindow;

//Initializes the window system, also checks if vulkan is supported
//Include all such initialization stuff here, so this function should and be called only once
int initWindowContext();

//Deletes and frees everything, need to be called at last
void freeWindowContext();

struct JptWindow createWindow();

void destroyWindow(struct JptWindow* pWindow);

//Gives back a Array of const char * containing 
//vulkan extensions required
Array getReuiredExtensions();

int shouldWindowClose(JptWindow window);

void pollWindowEvents(JptWindow window);